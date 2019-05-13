/*
*   指针的参数和返回值
*/
#include <stdio.h>

int *swap(int *px, int *py)
{
    int temp;
    temp = *px;     /* 定义了 */
    *px = *py;
    *py = temp;
    return px;
}

int main(void)
{
    int i = 10, j =20;
    int *p = swap(&i, &j);
    printf("now i=%d j=%d *p=%d\n", i, j, *p);
    return 0;
}