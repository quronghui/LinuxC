/*
*   client.c
*   1)是从命令行参数中获得一个字符串发给服务器,
*     然后接收服务器返回的字符串并打印。
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>



#define MAXLINE 80
#define SERC_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;

    if(argc != 2 ){
        fputs("usage: ./client message", stderr);
        exit(1);
    }
    str = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);    // 在connect连接之前，进行初始化
    servaddr.sin_port = htons(SERC_PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    // while(1);
    write(sockfd, str, strlen(str));
    
    n = read(sockfd, buf, MAXLINE);
    printf("Response from server:\n");
    write(STDOUT_FILENO, buf, n);

    close(sockfd);
    return 0;
}