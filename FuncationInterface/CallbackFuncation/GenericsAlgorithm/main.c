/*
*   回调函数的一个典型应用就是实现类似C++的泛型算法(Generics Algorithm)
*       (1)从任意数组中找出最大值；
*       (2)实现者不知道如何去比较，调用者需要提供一个作比较早作的回调函数
*/
#include <stdio.h>

typedef struct{
    const char *name;
    int score;
}student_t;    //结构体变量定义的时候直接初始化



int main(void)
{
    student_t list[4] = {{"Tom", 68}, {"Jerry", 72}, {"Moby", 60}, {"Kirby", 89}};    /*结构体的赋值*/                                      
    student_t *plist[4] = {&list[0], &list[1], &list[2],  &list[3]};    /*数组传递给结构体类型的指针*/
    student_t *pmax = max((void **)plist, 4, cmp_student);
    return 0;
}