/*
*   数据类型的标志位
*   1. 项目描述：枚举类型的结构体，输出的结果是一个递增的常量
*/
#include <stdio.h>

// 枚举类型：枚举类型的成员和变量名在同一个空间，不能定义成同样的名字。
enum coordinate_type        // 类似于Struct的Tag,enum代表的是枚举类型
{                           // 代表常量Rectangular（直角坐标） == 0 ；
    Rectangular = 4, Polar    // 代表常量Polar(极坐标) == 1
                            // 如果Rectangular==1，那么Polar == 2;递增
};
int main(void)
{
    int Rectangular;        // 测试同样的名字属性，会出什么问题
    printf("Test %d  %d\n", Rectangular,Polar);
    return 0;
}

// 输出结果为 0, 5， 