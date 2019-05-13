/*
*   数据抽像
*   1. 项目描述：提供一个完整的调用方式，关于复数
        （1）直角坐标系：由实部和虚部组成
        （2）极坐标系：由模和幅角组成
*   2. 代码分块：（1）结构体定义正常；
               （2） 复数的基础存储，#include "PluralStorage.cpp" 
               （3） 复数的运算， #include "PluralCalculate.cpp"
*/

#include <stdio.h>
#include "DataAbstraction.h"            // 这个头文件就只用包含一次，避免重复定义
#include "PluralCalculate.cpp"


int main()
{
    struct complex_struct z1 = {1.0, 2.0};
    struct complex_struct z2 = {3.0, 6.0};
    struct complex_struct z;
    struct complex_struct s;

    z = add_complex(z1, z2);
    printf("Test: z = %f +%fi \n", z.x, z.y);

    s = mul_complex(z1, z2);
    printf("Test: s = %f +%fi \n", s.x, s.y);
    return 0;
}