/*
*   数据抽像
*   1. 项目描述：复数的运算层，调用PlualStorage.cpp 里面的函数
        （1）加减运算；
        （2）乘除运算；
        （3）运算时可以不用改变的。
*/

#include "PluralStorage.cpp"               

/*
*  功能函数的设计
*/
// 求两个复数的加减运算
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_for_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_for_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}
// 球两个复数的乘除运算

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_for_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}
struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_for_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));

}
