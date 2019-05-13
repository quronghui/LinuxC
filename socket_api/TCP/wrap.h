/* wrap.h */
#ifndef WRAP_H
#define WRAP_H

#include <sys/socket.h>

extern void perr_exit(const char *s);
extern int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
extern void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
extern void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
extern void Listen(int fd, int backlog);
extern int Socket(int family, int type, int protocol);
extern ssize_t Read(int fd, void *ptr, size_t nbytes);
extern ssize_t Write(int fd, const void *ptr, size_t nbytes);
extern void Close(int fd);
extern ssize_t Readn(int fd, void *vptr, size_t n);   
extern ssize_t Writen(int fd, const void *vptr, size_t n);
extern ssize_t Readline(int fd, void *vptr, size_t maxlen);
static ssize_t my_read(int fd, char *ptr);

#endif