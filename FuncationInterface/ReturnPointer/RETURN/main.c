/*
*   动态分配内存并返回指针
*       (1)unit_t *alloc_unit(void)
*       (2)返回值分配内存就只需要一层指针
*/
#include <stdio.h>
#include "ret_allocator.h"

int main(void)
{
    unit_t *p = alloc_unit();
    printf("number: %d\nmsg: %s\n", p->number, p->msg);
    free_unit(p);
    p = NULL;
    return 0;
}