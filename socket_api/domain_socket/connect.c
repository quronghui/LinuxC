/*
*   connect.c
*   1) 以下是客户端的connect模块;
*   2) UNIX Domain Socket客户端一般要显式调用bind函数,而不依赖系统自动分配的地址。
*/
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CLI_PATH "/var/tmp/"

/*
* Create a client endpoint and connect to a server.
* Returns fd if all OK, <0 on error.
*/
int cli_connect(const char *name)
{
    int fd, len, err, rval;
    struct sockaddr_un un;

    /* create a UNIX domain stream socket */
    if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
        return (-1);

    /* fill socket address structure with our address */
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    sprintf(un.sun_path, "%s%05d", CLI_PATH, getpid());
    len = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    
    unlink(un.sun_path);
    if(bind(fd, (struct sockaddr *)&un, len) < 0 ){
        rval = -2;
        goto errout;
    }

    /* fill socket address structure with server's address */
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, name);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(name);
    if(connect(fd, (struct sockaddr *)&un, len) < 0 ){
        rval = -4;
        goto errout;
    }
    return (fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return(rval);
}
