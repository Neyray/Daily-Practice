#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

// ── 辅助函数：判断 str 中是否包含子串 sub ──
int
contains(char *str, char *sub)
{
    int slen = strlen(str);
    int sublen = strlen(sub);

    if(sublen == 0) return 1;      // 空子串，总是匹配
    if(sublen > slen) return 0;    // 子串比原串长，不可能匹配

    // 滑动窗口：逐位比较
    for(int i = 0; i <= slen - sublen; i++){
        int j;
        for(j = 0; j < sublen; j++){
            if(str[i+j] != sub[j])
                break;
        }
        if(j == sublen)   // 全部字符匹配
            return 1;
    }
    return 0;
}

// ── 核心函数：判断文件名 filename 是否匹配模式 pattern ──
//
//  *example   → star_prefix=1, star_suffix=0, core="example"
//  example*   → star_prefix=0, star_suffix=1, core="example"
//  *example*  → star_prefix=1, star_suffix=1, core="example"
//  example    → star_prefix=0, star_suffix=0, core="example"
//
int
match_pattern(char *filename, char *pattern)
{
    int plen = strlen(pattern);

    // 判断首尾是否有星号
    int star_prefix = (pattern[0] == '*');
    int star_suffix = (pattern[plen-1] == '*');

    // 提取核心字符串（去掉首尾星号）
    char core[256];
    int start = star_prefix ? 1 : 0;          // 核心从哪里开始
    int end   = star_suffix ? plen-1 : plen;  // 核心到哪里结束
    
    // 边界检查：如果模式只有一个 '*'
    if(start >= end){
        // 例如 pattern = "*"，匹配所有文件
        return 1;
    }

    // 复制核心部分到 core
    int core_len = end - start;
    memmove(core, pattern + start, core_len);
    core[core_len] = '\0';

    int flen = strlen(filename);

    // 根据星号组合选择匹配方式
    if(star_prefix && star_suffix){
        // *example* → 包含 core 即可
        return contains(filename, core);
    }
    else if(star_prefix){
        // *example → 文件名以 core 结尾
        if(flen < core_len) return 0;
        // 比较 filename 末尾 core_len 个字符
        return strcmp(filename + flen - core_len, core) == 0;
    }
    else if(star_suffix){
        // example* → 文件名以 core 开头
        if(flen < core_len) return 0;
        // 比较 filename 前 core_len 个字符
        return strncmp(filename, core, core_len) == 0;
    }
    else{
        // 无星号 → 完全匹配
        return strcmp(filename, core) == 0;
    }
}

// ── strncmp：xv6 ulib 没有提供，手动实现 ──
// 比较 s1 和 s2 的前 n 个字符
int
strncmp(char *s1, char *s2, int n)
{
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
        if(s1[i] == '\0')
            return 0;
    }
    return 0;
}

// ── 递归查找函数（与 find.c 结构完全相同，只改了匹配方式）──
void
findx(char *path, char *pattern)
{
    char buf[512], *p;
    int fd;
    struct dirent de;
    struct stat st;

    if((fd = open(path, 0)) < 0){
        fprintf(2, "findx: cannot open %s\n", path);
        return;
    }

    if(fstat(fd, &st) < 0){
        fprintf(2, "findx: cannot stat %s\n", path);
        close(fd);
        return;
    }

    switch(st.type){

    case T_FILE:
        // 提取文件名（最后一个 '/' 之后的部分）
        p = path + strlen(path);
        while(p >= path && *p != '/')
            p--;
        p++;  // p 指向文件名

        // 用 match_pattern 替代原来的 strcmp
        if(match_pattern(p, pattern))
            printf("%s\n", path);
        break;

    case T_DIR:
        if(strlen(path) + 1 + DIRSIZ + 1 > sizeof(buf)){
            printf("findx: path too long\n");
            break;
        }

        strcpy(buf, path);
        p = buf + strlen(buf);
        *p++ = '/';

        while(read(fd, &de, sizeof(de)) == sizeof(de)){
            if(de.inum == 0)
                continue;

            // 跳过 "." 和 ".."，防止无限递归
            if(strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0)
                continue;

            memmove(p, de.name, DIRSIZ);
            p[DIRSIZ] = 0;

            findx(buf, pattern);  // 递归
        }
        break;
    }

    close(fd);
}

int
main(int argc, char *argv[])
{
    if(argc < 3){
        fprintf(2, "Usage: findx <directory> <pattern>\n");
        fprintf(2, "  pattern examples: abc  abc*  *abc  *abc*\n");
        exit();
    }

    findx(argv[1], argv[2]);
    exit();
}