/*
*   exec.c
*   1),第一个"ps" 是程序名,execlp函数要在PATH环境变量中找到这个程序并执行它
*   2),而第二个"ps" 是第一个命令行参数,execlp函数并不关心它的值,只是简单地把它传给ps 程序,
*/
#include <unistd.h>
#include <stdlib.h>
 #include <stdio.h>

extern char **environ;

int main(void)
{
    execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
    /*ps -- report a snapshot of the current processes.*/
    perror("exec ps");
    exit(1);
}