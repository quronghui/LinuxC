/*
*   print.c
*     (1)有了err_sys 函数,不仅简化了main函数的代码,
*       (2)而且可以把fopen 的错误提示打印得非常清楚,有源代码行号,有打开文件的路径名,一看就知道哪里出错了。
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>

#define MAXLINE 80

void err_sys(const char *fmt, ...)
{
    int err = errno;
    char buf[MAXLINE + 1];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, MAXLINE, fmt, ap);
    snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(err));
    strcat(buf, "\n");
    fputs(buf, stderr);
    va_end(ap);
    exit(1);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    if(argc != 2){
        fputs("Usage: ./a.out pathname\n", stderr);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL)
        err_sys("Line %d - Open file %s", __LINE__, argv[1]);
    printf("Open %s OK\n", argv[1]);
    fclose(fp);
    return 0;
}