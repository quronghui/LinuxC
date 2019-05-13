/*
*   回调函数
*       实现了一个repeat_three_times 函数,可以把调用者传来的任何回调函数执行三次
×       调用者：提供函数组合后的操作方式（打印，排序）
*/
#include <stdio.h>
#include "para_callback.h"


void say_hello(void *str)
{
    printf("Hello %s\n", (const char *)str);
}


void count_numbers(void *num)
{
    int i;
    for(i=1; i <= (int)num; i++)
         printf("%d ", i);
    putchar('\n');
}


int main()
{
    repeat_three_times(say_hello, (void *)"Guys");  /*这里的函数的调用：为了组成上面的两个函数*/
    repeat_three_times(count_numbers, (void *)4);
    return 0;
}