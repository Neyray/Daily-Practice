#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <setjmp.h>
#include <errno.h>

extern char** environ;

struct MyResult {
    int code;     // 正常退出码或 -信号号
    int timeout;  // 1 = 超时，0 = 正常
};
static volatile sig_atomic_t child_pid = 0;

void alarm_handler(int sig) {
    if (child_pid > 0) {
        kill(child_pid, SIGKILL); // 超时后强制终止子进程
    }
}

struct MyResult mysystem(const char* command, int timeout_sec) {
    struct MyResult res = { 0, 0 };
    pid_t pid;
    struct sigaction sa;
    sigset_t mask;

    // 阻塞SIGALRM防止竞态条件
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    // 配置信号处理函数
    sa.sa_handler = alarm_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        res.code = -1; // 信号处理设置失败
        return res;
    }

    pid = fork();
    if (pid < 0) { // fork失败
        res.code = -1;
        return res;
    }
    else if (pid == 0) { // 子进程执行命令
        char* argv[] = { "sh", "-c", (char*)command, NULL };
        execve("/bin/sh", argv, environ);
        // execve失败时直接退出，返回127
        _exit(127); // 使用_exit避免冲刷缓冲区
    }

    // 父进程设置全局子进程PID
    child_pid = pid;
    sigprocmask(SIG_UNBLOCK, &mask, NULL); // 解除SIGALRM阻塞
    alarm(timeout_sec); // 启动定时器

    int status;
    if (waitpid(pid, &status, 0) == -1) { // 等待子进程
        if (errno == EINTR) { // 被SIGALRM中断（超时）
            res.timeout = 1;
            // 再次等待确保子进程终止
            if (waitpid(pid, &status, 0) != -1) {
                if (WIFSIGNALED(status))
                    res.code = -WTERMSIG(status); // 记录信号
            }
            else {
                res.code = -1; // 异常情况
            }
        }
        else {
            res.code = -1; // 其他错误
        }
    }
    else { // 正常结束
        res.timeout = 0;
        if (WIFEXITED(status))
            res.code = WEXITSTATUS(status); // 正常退出码
        else if (WIFSIGNALED(status))
            res.code = -WTERMSIG(status); // 被信号终止
    }

    // 清理定时器和全局变量
    alarm(0);
    child_pid = 0;
    return res;
}

