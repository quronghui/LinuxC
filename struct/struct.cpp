/*
*   本节将以结构体为例来讲解数据类型的组合和抽象。
*   1. 项目描述：通过结构体定义复数
        （1）直角坐标系：由实部和虚部组成
        （2）极坐标系：由模和幅角组成
*   2. 项目描述：将结构体当做函数的参数和返回值来传递
        （1）结构体当做函数的参数，比如 int main,中的int
        (2) struct complex_struct 当做函数 add_complex的参数
*/

#include <stdio.h>

// Tag定义在函数外面,就像全局变量一样
struct complex_struct            // complex_struct 是标识符,既然是标识符,那么它的命名规则就和变量一样
{                                // 但是complex_struct不表示变量，而是表示类型,类似于int的符合类型
    double x, y;                 /* data */
};                         // 用这个符合类型名来定义变量；

// 函数申明
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2);


int main()
{   
    /** 项目一 : 结构体的定义和初始化 **/
    struct complex_struct z;   // 定义了complex_struct 这个Tag,后都可以直接用struct complex_struct 来代替类型名
    // struct complex_struct z = { 3.0, 4.0 }; // 定义的时候初始化
    double x = 3.0;             // 不等同于Tag的z.x；
    z.x = x;                   // 变量访问成员，通过z.x 
    z.y = 4.0;
    if(z.y < 0)
        printf("z = %f%fi\n", z.x, z.y);
    else
        printf("z = %f + %fi\n", z.x, z.y);
    
    /** 项目二的测试 **/
    z = add_complex(z,z);       // 结构体的传递
    printf("Test 2: z = %f +%fi \n", z.x, z.y);

    printf("Hello world!\n");
    return 0;
}

// 项目二,项目描述：将结构体当做函数的参数和返回值来传递
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
    z1.x = z1.x + z2.x;
    z1.y = z1.y + z2.y;
    return z1; 
}