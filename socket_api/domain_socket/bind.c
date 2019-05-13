/*
*   bind.c
*   1) 将UNIX Domain socket绑定到一个地址。
*   2) offsetof(struct sockaddr_un, sun_path)就是取sockaddr_un结构体的sun_path成员在结构体中的偏移
*/
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main(void)
{
    int fd, size;
    struct sockaddr_un un;

    memset(&un, 0, sizeof(un)); /* init */
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, "foo.socket");
    if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0 ){
        perror("socket error");
        exit(1);
    }
    size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    if(bind(fd, (struct sockaddr *)&un, size) < 0 ){
        perror("bind error");
        exit(1);
    }
    printf("UNIC domain socket bound\n");
    exit(0);
}