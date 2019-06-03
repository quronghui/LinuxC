/*
*   accept.c
*   1) listen之后，accept接受连接
*/
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int serv_accept(int listenfd, uid_t *uidptr)
{
    int clifd, len, err, rval;
    time_t  staletime;
    struct sockaddr_un un;
    struct stat statbuf;

    len = sizeof(un);
    if((clifd = accept(listenfd, (struct sockaddr *)&un, &len)) < 0 )
        return (-1);
    
    /*obtain the client's uid from its calling adress*/
    len -= offsetof(struct sockaddr_un, sun_path);
    un.sun_path[len] = 0;

    if(stat(un.sun_path, &statbuf) < 0 ){
        rval = -2;
        goto errout;
    }
    if(S_ISSOCK(statbuf.st_mode) == 0 ){
        rval = -3;      /* not a socket */
        goto errout;
    }
    if(uidptr != NULL)
        *uidptr = statbuf.st_uid;
    unlink(un.sun_path);
    return (clifd);
errout:
    err = errno;
    close(clifd);
    errno = err;
    return(rval);
}