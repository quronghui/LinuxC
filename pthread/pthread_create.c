/*
*   pthread_create()
*   1)get the process pid and thread tid
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t  pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();   // 直接打印ntid，不调用pthread_self
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printids(arg);
    return NULL;
}

int main(void)
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if(err != 0){
        fprintf(stderr, "can't create thread: %s\n", strerror(err));
        exit(1);
    }
    printids("main thread: ");
    sleep(1);
    return 0;
}