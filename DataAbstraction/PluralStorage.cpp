/*
*   数据抽像
*   1. 项目描述：复数的存储表示层
        只有实部，虚部，模和辐角的复数
        复数的直角坐标或者极坐标的表示。
*/

#include <stdio.h>
#include <math.h>
#include "DataAbstraction.h"             // 不能在包含头DataAbstraction.h头文件了，否则会造成定义重复；除非在DataAbstraction.h里面加上#ifndef _TEST_H_

/*
*  1.基础函数的设计,选直角坐标进行存储
*/
double real_part(struct complex_struct z)
{
    return z.x;
}
double img_part(struct complex_struct z)
{
    return z.y;
}
double magnitude(struct complex_struct z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}
double angle(struct complex_struct z)
{
    double PI = acos(-1.0);                 // 计算得到PI=3.14
    // printf("Test PI is %f \n", PI);
    if (z.x > 0) {
        return atan(z.y / z.x);
    }
    else
    {
        return atan(z.y / z.x) + PI;
    }
}

// 极坐标和直角坐标的转换函数
struct complex_struct make_for_real_img(double x, double y)
{
    struct complex_struct z;
    //z.t = Rectangular;
    z.x = x;
    z.y = y;
    return z;
}
struct complex_struct make_for_mag_ang(double r, double A)
{
    struct complex_struct z;
    //z.t = Polar;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

/*
*   2.极坐标形式存储：
       增加数据类型的标志位--enum: 0/直角坐标；1/极坐标
       在 DataAbstraction.h 增加标志位
    Bug : 
        枚举类型如何引用呢  
*/

// // 极坐标和直角坐标的转换函数
// struct complex_struct make_for_real_img(double x, double y)
// {
//     struct complex_struct z;
//     z.t = Rectangular;
//     z.x = x;
//     z.y = y;
//     return z;
// }
// struct complex_struct make_for_mag_ang(double r, double A)
// {
//     struct complex_struct z;
//     z.t = Polar;
//     z.x = r * cos(A);
//     z.y = r * sin(A);
//     return z;
// }
