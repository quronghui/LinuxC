/*
*   运算符规则
*   项目1介绍： 运算符的优先级顺序
×       （1）逻辑运算符的优先级，低于算数，移位，关系，相等性运算符的
*/
#include <stdio.h>

int main(void)
{
    int i = 0;
    for(; i <= 1024; i++)
    {
        if ((i & 0xff) == 0) {              // i & 0xff == 0 ;先运行 “==”
            printf("Value is %d\n", i);
        }
    }
    return 0;
}