/*
*   堆栈程序的测试  
*   项目1介绍： 用堆栈实现倒序打印
*        (1) 所有元素类型相同: 堆栈的存储：可以用数组实现;访问操作：通过函数接口提供
*/
#include <stdio.h>


char stack[512];
int top = 0;

void push(char c)
{
    stack[top] = c;
    top++;
}

char pop(void)
{
    top--;
    return stack[top];
}

int is_empty(void)
{
    return top == 0;
}

int main(void)
{
    push('a');
    push('b');
    push('c');

    while (!is_empty())
        putchar(pop());
    putchar('\n');
    
    return 0;
}