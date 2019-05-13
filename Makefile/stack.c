/* stack.c */
/* stack.c 是没有 int stack() 函数的，所以不用加 #include <stdio.h> */

#include "stack.h"

static item_t stack[512];
static int top = 0;

void push (struct point p)
{
    stack[top] = p;
    top++;
}

struct point pop(void)
{
   top--;
   return stack[top];
}

int is_empty(void)
{
    return top == 0;
}