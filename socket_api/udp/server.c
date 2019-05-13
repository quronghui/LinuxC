/*
*   server.c
*   1) UDP 过程中少了listen and accept
*   2) 不用关闭文件描述符
*   3) recvfrom error: Transport endpoint is not connected
*      udp 中的采用的是数据报文，并非流 SOCK_STREAM --> SOCK_DGRAM 
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;   // <netinet/in.h>
    socklen_t cliaddr_len;  // <sys/socket.h> 
    int sockfd;   // 定义server 的文件描述符
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];  // IPV4的网络地址，IP地址的长度16
    int i, n;

    /* SOCK_STREAM --> SOCK_DGRAM */
    sockfd = Socket(AF_INET, SOCK_DGRAM, 0); // which case protocol can be specified as 0

    // 初始化bind() 的address 参数
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   // host to network 序列转换
    servaddr.sin_port = htons(SERV_PORT);

    Bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    printf("Accepting connections ...\n");

    while(1){
        cliaddr_len = sizeof(cliaddr);
        n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &cliaddr_len );
        if(n == -1)
            perr_exit("recvfrom error");
        printf("received from %s at PORT %d\n", 
            inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),    // 将32位的地址，转换成网络地址形式 
            ntohs(cliaddr.sin_port));
        for(i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        n = sendto(sockfd, buf, n, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
        if(n == -1)
            perr_exit("send to error");
    }  
}