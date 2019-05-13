/* 
*   main 原型参数 :
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int *argv[])
{
    int i;
    for(i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    return 0;
}

/*  编译执行
*       gcc main.c -o main
*       ./main a b c
*/