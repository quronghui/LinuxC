/*
*   堆栈程序的拆分
*   项目1介绍： 主函数
*        
*/
#include <stdio.h>
//#include "stack.h"
#include "stack.c"     // 有了extern 就不用加上函数引用了

//1.函数的声明，extern可有可无
// extern void push(char);
// extern char pop(void);
// extern int is_empty(void);

int a, b = 1; 
int main(void)
{
    // // 函数的声明在内部
    // void push(char);
    // char pop(void);
    // int is_empty(void);

    push('a');
    push('b');  
    push('c');

    while (!is_empty())
        putchar(pop());
    putchar('\n');
    
    return 0;
}