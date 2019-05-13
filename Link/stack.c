/*
*   堆栈程序的拆分
*   项目1介绍： stack.c函数
*       （1）这里的top总是指向栈顶元素的下一个元素；
*       (2) 栈的元素存储是由高地址到低地址，进行递增
*        
*/
#include "stack.h"

char stack[512];
int top = -1;

void push(char c)
{
    stack[++top] = c;   // top指向的是下一个元素
    // top++;
}

char pop(void)
{
    // top--;
    return stack[top--];
}

int is_empty(void)
{
    return top == -1;
}