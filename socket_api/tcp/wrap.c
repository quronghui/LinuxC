/*
*   wrap.c
*   1)把与socket相关的一些系统函数加上错误处理代码包装成新的函数,做成一个模块wrap.c:
*   2)依赖文件wrap也要编译成wrap.o库文件；而不是编译成可执行文件;一直报错，未声明使用
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include "wrap.h"

void perr_exit(const char *s)
{
    perror(s);  //print a system error message
    exit(1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;
again:          // goto 语句的跳转
    if( (n = accept(fd, sa, salenptr)) < 0 ){
        if((errno == ECONNABORTED) || (errno == EINTR) )
            goto again;
        else
            perr_exit("accept error");
    }
    return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if(bind(fd, sa, salen) < 0 )
        perr_exit("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if(connect(fd, sa, salen) < 0 )
        perr_exit("connect error");
}

void Listen(int fd, int backlog)
{
    if(listen(fd, backlog) < 0 )
        perr_exit("listen error");
}

int Socket(int family, int type, int protocol)
{
    int n;
    if((n = socket(family, type, protocol)) < 0 )
        perr_exit("socket error");
    return n;
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
    ssize_t n;
again:
    if((n = read(fd, ptr, nbytes)) == -1 ){
        if(errno == EINTR)
            goto again;
        else
            return -1;
    }
    return n;
}

ssize_t Write(int fd, const void *ptr, size_t nbytes)
{
    ssize_t n;
again:
    if((n = write(fd, ptr, nbytes)) == -1 ){
        if(errno == EINTR)
            goto again;
        else
            return -1;
    }
    return n;
}

void Close(int fd)
{
    if(close(fd) == -1 )
        perr_exit("close error");
}

/* 应用层协议的各字段长度固定，用readn方便 */
ssize_t Readn(int fd, void *vptr, size_t n)     
{
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = vptr;
    nleft = n;
    while(nleft > 0){
        if((nread = read(fd, ptr, nleft)) < 0 ){
            if(errno == EINTR)
                nread = 0;
            else 
                return -1;
        }else if (nread == 0)
            break;
        nleft -= nread;
        ptr += nread;
    }
    return n - nleft;
}

ssize_t Writen(int fd, const void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;
    char *ptr;

    ptr = vptr;
    nleft = n;
    while(nleft > 0 ){
        if((nwritten = write(fd, ptr, nleft)) <= 0 ){
            if(nwritten < 0 && errno == EINTR)
                nwritten = 0;   
             else
                return -1;    
        }
        nleft -= nwritten;
        ptr += nwritten;    
    }
    return n;
}

/* 应用层协议都是带有可变长字段的 ,实现一个类似于fgets的readline函数*/
static ssize_t my_read(int fd, char *ptr)
{
    static int read_cnt;
    static char *read_ptr;
    static char read_buf[100];

    if(read_cnt <= 0){
    again: 
        if((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0){
            if(errno == EINTR)
                goto again;
            return -1;
        }
        else if(read_cnt == 0)
            return 0;
        read_ptr = read_buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}

ssize_t Readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char c, *ptr;

    ptr = vptr;
    for(n=1; n < maxlen; n++){
        if((rc = my_read(fd, &c)) == 1 ){
            *ptr++ =c;
            if(c == '\n')
                break;
        }
        else if(rc == 0){
            *ptr = 0;
            return n - 1;
        }
        else
            return -1;
    }
    *ptr = 0;
    return n;
}