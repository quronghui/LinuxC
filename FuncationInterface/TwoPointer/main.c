/*
*   两层指针:可以动态分配存储空间
*/
#include <stdio.h>
#include "para_allocator.h"

int main(void)
{
    unit_t *p=NULL;
    alloc_unit(&p);

    printf("number: %d\nmsg: %s\n", p->number, p->msg);
    free_unit(p);
    p = NULL;
    return 0;
}