/*
*   server.c
*   1)是从客户端读字符,然后将每个字符转换为大写并回送给客户端；
*   2)server 只能满足单个client的一次请求；
*   3)server -- 单个client的多次请求：将应答写在while(1)中；
*   4)server -- fork(); 处理多个client的请求
*   5)在同一个终端，关闭server后，还能重新开启server
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
    int listenfd, connfd;   // 定义server 和client的文件描述符
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];  // IPV4的网络地址，IP地址的长度16
    int i, n, f;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0); // which case protocol can be specified as 0

    /*5)在同一个终端，关闭server后，还能重新开启server */
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 初始化bind() 的address 参数
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   // host to network 序列转换
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 20);   // 最多 20 client

    printf("Accepting connections ...\n");

    /* 3)server -- 单个client的多次请求：将应答写在while(1)中；*/
    // while(1){
    //     cliaddr_len = sizeof(cliaddr);
    //     connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
    //     while(1){
    //         n = Read(connfd, buf, MAXLINE);
    //         if(n == 0){
    //             printf("the other side has been closed.\n");
    //             break;
    //         }
    //         printf("received from %s at PORT %d\n", 
    //             inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),    // 将32位的地址，转换成网络地址形式 
    //             ntohs(cliaddr.sin_port));
    //         for(i = 0; i < n; i++)
    //             buf[i] = toupper(buf[i]);
    //         Write(connfd, buf, n);
    //     }
    //     close(connfd);
    // }  

    /* 4)server -- fork(); 处理多个client的请求 */
    while(1){
        cliaddr_len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
        f = fork();
        if(f == -1){
            perror("call to fork");
            exit(1);
        }
        else if(f == 0){
            close(listenfd);
            while(1){
                n = Read(connfd, buf, MAXLINE);
                if(n == 0){
                    printf("the other side has been closed.\n");
                    break;
                }
                printf("received from %s at PORT %d\n", 
                    inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),    // 将32位的地址，转换成网络地址形式 
                    ntohs(cliaddr.sin_port));
                for(i = 0; i < n; i++)
                    buf[i] = toupper(buf[i]);
                Write(connfd, buf, n);
            }
            close(connfd);
            exit(1);
        }
        else          
            close(connfd);
    }  
}