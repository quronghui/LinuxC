/*
*   移位运算
*   项目1介绍： 估计是类型转转换的时候发生了溢出的现象
*        0xcffffff3 >> 2 = 33fffffc
*        i>>2 = f3fffffc  ; 为啥左边多了两个1
*/

#include <stdio.h>

int main(void)
{
    int i = 0xcffffff3;
    printf("i = %d\n", i );
    printf("0xcffffff3 >> 2 = %x\n", 0xcffffff3 >> 2);
    printf("i>>2 = %x\n", i >> 2);
    return 0;
}
