/*
*   client.c
*   1)  SOCK_STREAM --> SOCK_DGRAM
*   2) UDP 不用考虑多个client的链接
×       不用考虑同意终端关闭server后不能重新开启的现象
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>

#include "wrap.h"

#define MAXLINE 80
#define SERC_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char str[INET_ADDRSTRLEN];
    socklen_t servaddr_len;

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);    // 在connect连接之前，进行初始化
    servaddr.sin_port = htons(SERC_PORT);

    while(fgets(buf, MAXLINE, stdin) != NULL ){
        n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
        if(n == -1)
            perr_exit("sendto error");
        n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
        if(n == -1)
            perr_exit("recvfrom error");
        Write(STDOUT_FILENO, buf, n);
    }
    Close(sockfd);
    return 0;
}