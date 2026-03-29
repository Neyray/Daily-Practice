#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

// 递归查找函数：在 path 目录下查找名为 name 的文件
void
find(char *path, char *name)
{
    char buf[512], *p;
    int fd;
    struct dirent de;   // 目录项（包含 inum 和 name）
    struct stat st;     // 文件状态（包含 type）

    // 第一步：打开路径
    if((fd = open(path, 0)) < 0){
        fprintf(2, "find: cannot open %s\n", path);
        return;
    }

    // 第二步：获取文件信息
    if(fstat(fd, &st) < 0){
        fprintf(2, "find: cannot stat %s\n", path);
        close(fd);
        return;
    }

    // 第三步：根据类型分别处理
    switch(st.type){

    case T_FILE:
        // 如果是文件，检查文件名是否匹配
        // path 可能是 "./a/b"，需要提取最后一段
        // 找到最后一个 '/' 后面的部分
        p = path + strlen(path);
        while(p >= path && *p != '/')
            p--;
        p++;  // p 现在指向最后一个文件名
        
        if(strcmp(p, name) == 0)
            printf("%s\n", path);
        break;

    case T_DIR:
        // 如果是目录，构造子路径并递归
        if(strlen(path) + 1 + DIRSIZ + 1 > sizeof(buf)){
            printf("find: path too long\n");
            break;
        }

        // 构造 "path/" 作为前缀
        strcpy(buf, path);
        p = buf + strlen(buf);
        *p++ = '/';   // 加上斜杠，p 指向斜杠后面的位置

        // 逐条读取目录项
        while(read(fd, &de, sizeof(de)) == sizeof(de)){
            if(de.inum == 0)    // 空目录项，跳过
                continue;
            
            // 跳过 "." 和 ".."，防止无限递归！
            if(strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0)
                continue;

            // 拼接完整路径：buf = "path/de.name"
            memmove(p, de.name, DIRSIZ);
            p[DIRSIZ] = 0;  // 确保字符串以 '\0' 结尾

            // 递归查找
            find(buf, name);
        }
        break;
    }

    close(fd);
}

int
main(int argc, char *argv[])
{
    if(argc < 3){
        fprintf(2, "Usage: find <directory> <filename>\n");
        exit();
    }

    find(argv[1], argv[2]);
    exit();
}