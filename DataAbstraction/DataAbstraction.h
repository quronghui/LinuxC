/*
*   数据抽像
*   1. 项目描述：定义了一个结构体的类型，主函数的头文件定义一个结构体,当做一个复合类型使用
        包含两个属性，方便复数Plural 运算
*/

#include <stdio.h>

#ifndef _TEST_H_            // 为了避免引用DataAbstraction.h，造成重复定义的问题；  
#define _TEST_H_            // 需要加这个代码

// 枚举类型：枚举类型的成员和变量名在同一个空间，不能定义成同样的名字。
enum coordinate_type        // 类似于Struct的Tag,enum代表的是枚举类型
{                           // 代表常量Rectangular（直角坐标） == 0 ；
    Rectangular, Polar      // 代表常量Polar(极坐标) == 1
};

// 结构体类型：枚举类型的成员和变量名不在同一个空间。
struct complex_struct       // Struct 类型的Tag
{
    //enum coordinate_type t; // 常量标志位    
    double x, y;              /* data */
};

#endif