/*
*   传入参数和传出参数
*       结论：单层指针是不能分配存储空间的，所以是NULL
*/
#include <stdio.h>
#include "populator.h"

int main(void)
{
    unit_t u;

    set_unit(&u);
    printf("number: %d\nmsg: %s\n", u.number, u.msg);
    return 0;
}