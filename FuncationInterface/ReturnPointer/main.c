/*
*   返回值是指针的情况
*       (1)这个程序的运行结果是Sunday Monday吗?
*       (2)结果：为啥返回结果都是 Sunday，Sunday
*/
#include <stdio.h>
#include "ret_ptr.h"

int main(void)
{
    printf("%s %s\n", get_a_day(0), get_a_day(1));
    return 0;
}