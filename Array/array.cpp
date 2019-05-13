/*
*   数组应用实例
*   1. 项目描述：统计随机数中 0-9 出现的次数
        （1） rand() % 10, 生成随机数0-9
        （2） 统计出现的次数
        (3)随机数是均匀的
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100000

int a[N];

void gen_random(int upper_bound)    //upper_bound 表示生成的随机数，上边界是多少。
{
    int i;
    for(i =0; i < N; i ++){
        a[i] = rand() % upper_bound;            
    }
}

int howmany(int value)
{
    int count =0, i;
    for(i = 0; i < N; i++){
        if ( a[i] == value) {
            ++count;            /* code */
        }
    }
    return count;
}

int main(void)
{
    int i;
    gen_random(10);
    printf("value\thow many.\n");
    for(i = 0; i < 10; i++){
        printf("%d\t%d\n", i, howmany(i));
    }
    return 0;
}   

