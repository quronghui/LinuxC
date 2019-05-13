/*
*   blocking_read_terminal.c
*   1) Shell进程创建a.out 进程,a.out 进程开始执行,而Shell进程睡眠等待a.out 进程退出。
*   2)a.out 调用read 时睡眠等待,直到终端设备输入了换行符才从read 返回,read只读走10个
*     字符,剩下的字符仍然保存在内核的终端设备输入缓冲区中。
*   3) a.out 进程打印并退出,这时Shell进程恢复运行,Shell继续从终端读取用户输入的命令,
*/
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char buf[10];
    int n;
    n = read(STDIN_FILENO, buf, 10);
    if(n < 0){
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    return 0;
}
