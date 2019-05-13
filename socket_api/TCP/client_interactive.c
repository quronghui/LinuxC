/* client_interactive.c 
*   1) client and server 交互式进行应答
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

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);    // 在connect连接之前，进行初始化
    servaddr.sin_port = htons(SERC_PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    while(fgets(buf, MAXLINE, stdin) != NULL ){
        Write(sockfd, buf, strlen(buf));
        n = Read(sockfd, buf, strlen(buf));
        if(n == 0)
            printf("the other side has been closed.\n");
        else
            Write(STDOUT_FILENO, buf, n);
    }
    Close(sockfd);
    return 0;
}
