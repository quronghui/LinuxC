/*
*   fgetc and getchar
*   fputc and putchar
*       (1) 通过C标准库函数向文件中写入字符，并且读取字符
*       (2) 从终端输入时有两种方法表示文件结束 ctrl+D
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    int ch;

    if ((fp = fopen("file2", "w+")) == NULL)
    {
        perror("Open file file2\n");    /*perror 用于读取errno表示的字符串*/
        exit(1);
    }

    while((ch = getchar()) != EOF)
        fputc(ch, fp);
    
    rewind(fp); /* 重置函数fp */

    while((ch = fgetc(fp)) != EOF)
        putchar(ch);
    
    fclose(fp);
    return 0;
}
