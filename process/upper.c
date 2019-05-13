/*
*   upper.c
*   1) 转换小写位大写
*/
#include <stdio.h>

int main(void)
{
    int ch;
    while((ch = getchar()) != EOF ){
        putchar(toupper(ch));
    }
    return 0;
}