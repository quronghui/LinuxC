/*
*   select_server.c
*   1)select是网络程序中很常用的一个系统调用,它可以同时监听多个阻塞的文件描述符
*   2)不需要fork和多进程就可以实现并发服务的server。
*   3) 未使用
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char **argv)
{
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[__FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    socklen_t cliaddr_len;
    struct sockaddr_in  cliaddr, servaddr;
    
    listenfd = Socket(AF_INET, SOCK_STREAM, 0); // which case protocol can be specified as 0

    // 初始化bind() 的address 参数
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   // host to network 序列转换
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 20);   // 最多 20 client

    maxfd = listenfd;   /* initialize */
    maxi  = -1;         /* index into client[] array*/
    for(i = 0; i < FD_SETSIZE; i++)
        client[i] = -1;
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    for(;;){
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

    }
}