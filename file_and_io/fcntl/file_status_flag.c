/*
*   file_status_flag.c
*   !)通过函数fcntl函数，实现对终端文件参数的设置，实现O_NONBLOCK，实现非阻塞
*   2)函数的主体还是和Unblocking_read_terminal.c 一致
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"
int main(void)
{
    char buf[10];
    int n;
    int flags;
    flags =  fcntl(STDIN_FILENO, F_GETFL);
    flags |= O_NONBLOCK;
    if(fcntl(STDIN_FILENO, F_SETFL, flags) == -1){
        perror("fcntl");
        exit(1);
    }
tryagain:
    n = read(STDIN_FILENO, buf, 10);
    if(n < 0){
        if(errno == EAGAIN){
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            goto tryagain;
        }
        perror("read stdin");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    return 0;
}