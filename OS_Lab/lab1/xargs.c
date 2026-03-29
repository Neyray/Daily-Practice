#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"   // 提供 MAXARG 宏
#include "user/user.h"

int
main(int argc, char *argv[])
{
    // 参数检查：xargs 至少需要一个要执行的命令
    if(argc < 2){
        fprintf(2, "Usage: xargs <command> [args...]\n");
        exit();
    }

    // ── 第一步：把 xargs 自己的参数复制到 cmd_argv ──
    // 例如 "xargs echo bye"
    // argv[0]="xargs", argv[1]="echo", argv[2]="bye"
    // 我们需要构造 ["echo", "bye", <从stdin读来的内容>, 0]

    char *cmd_argv[MAXARG];  // 最终传给 exec 的参数数组
    int base_argc = 0;       // xargs 本身带来的参数个数

    // 从 argv[1] 开始复制（跳过 "xargs" 本身）
    for(int i = 1; i < argc; i++){
        cmd_argv[base_argc++] = argv[i];
    }
    // 此时 cmd_argv = ["echo", "bye"]，base_argc = 2

    // ── 第二步：循环从标准输入读取每一行 ──
    char buf[512];    // 存放从 stdin 读到的一行内容
    char c;           // 逐字符读取

    while(1){
        // 逐字符读一行，直到遇到 '\n' 或 EOF
        int i = 0;
        while(1){
            int n = read(0, &c, 1);  // 从 stdin(fd=0) 读 1 个字符
            if(n <= 0)               // EOF 或出错，退出外层循环
                goto done;
            if(c == '\n')            // 读到换行，这一行结束
                break;
            buf[i++] = c;            // 存入缓冲区
        }
        buf[i] = '\0';  // 字符串结尾

        // 如果读到空行就跳过
        if(i == 0)
            continue;

        // ── 第三步：把这一行作为额外参数加到 cmd_argv ──
        // 简单处理：把整行作为一个参数
        // （完整实现可以按空格拆分，这里按题目要求处理整行）
        cmd_argv[base_argc] = buf;
        cmd_argv[base_argc + 1] = 0;  // argv 末尾必须是 NULL

        // ── 第四步：fork + exec 执行命令 ──
        int pid = fork();
        if(pid < 0){
            fprintf(2, "xargs: fork failed\n");
            exit();
        }

        if(pid == 0){
            // 子进程：执行命令
            // cmd_argv[0] 是命令名，如 "echo"
            exec(cmd_argv[0], cmd_argv);
            // exec 失败才会到这里
            fprintf(2, "xargs: exec %s failed\n", cmd_argv[0]);
            exit();
        } else {
            // 父进程：等待子进程完成，再继续读下一行
            wait();
        }
    }

done:
    exit();
}