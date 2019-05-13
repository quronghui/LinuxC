/*
*   项目介绍：Gdb单步调试和跟踪函数调用
        测试gdb的单步调试调试命令。
*/
#include <stdio.h>

/*在一个范围内求和的函数*/
int add_range(int low, int high)
{
    int i, sum = 0;                    /*Bug 局部变量要定义初值，全局变量不定义初值时为0*/
    for (i = low; i <= high; i++){
        sum = sum + i;
    }
    return sum;
}

int main(void)
{
    int result[100];
    result[0] = add_range(1, 10);
    result[1] = add_range(1, 100);
    printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
    return 0;
}