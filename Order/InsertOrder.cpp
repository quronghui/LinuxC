/*
*   插入排序
*   项目1介绍：
*        (1)扑克，插入牌的思想，和前面的一一比较；
*        (2)和之前的双重for循环不同
*        (3)策略：每次添加一个到已排序的子序列中，时间复杂度是 O(n^2)
*/
#include <stdio.h>

#define LEN 5                       //预声明，用大写
int a[LEN] = {10, 5, 2, 4, 7};

void insertion_sort(void)           //C语言中的功能函数包含动词
{
    int i, j, key;
    for(j = 1; j < LEN; j++){
        printf("%d, %d, %d, %d, %d\n",
                a[0], a[1], a[2], a[3], a[4]);
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }
    printf("%d, %d, %d, %d, %d\n",
            a[0], a[1], a[2], a[3], a[4]);
}

int main(void)
{
    insertion_sort();
    return 0;
}