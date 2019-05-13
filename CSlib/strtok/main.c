/*
*   strtok.c 
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "abc:def:dajjk:898:";   // string,需要加‘[]’,字符串的保存类似于数组
    char *token = strtok(string, ":");      // delim 需要 “delim”，不是 'delim'
    printf("%s\n", token);
    while((token = strtok(NULL, ":")) != NULL ){    //将token指针指向的内存地址中，所有的token块都打印出来
        printf("%s\n", token);
    }
    return 0;
}