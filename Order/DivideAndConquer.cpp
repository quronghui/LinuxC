/*
*   归并排序
*   项目2介绍：
*       (1)相比较于插入排序策略：每次添加一个到已排序的子序列中，时间复杂度是 O(n^2)
*       (2)将时间复杂度降到 O(nlgn)。
*       (3)Gdb: 展开的方式看递归（这样很笨） -- 单步加断点的方式调试程序的每步结果。
*       (4)     捉住 Base Case 和 递推关系来理解，不能展开来看，这样就很乱了。
*/
#include <stdio.h>

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6 };

void merge(int start, int mid, int end)
{
    int n1 = mid - start +1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

    for(i = 0; i < n1; i++)
        left[i] = a[start + i];         /*left holds a[start ... mid]*/
    for(j = 0; j < n2; ++j)             /*++j, 返回的（j+1）*/
        right[j] = a[mid+1 + j];        /*right holds a[mid+1 ... end]*/
    i =j = 0;
    for(k = start; i < n1 && j < n2; ++k)
    {
        if (left[i] < right[j]) {
            a[k] = left[i];
            ++i;
        } else {
            a[k] = right[j];
            ++j;
        }
    }

    if (i < n1){                        /*left[] is not exhausted*/
        for (; i < n1; i++){
            a[k] = left[i];
            ++k;
        }
    }
    if(j < n2){
        for (; j < n2; j++){
            a[k] = right[j];
            ++k;
        }
    }
}


void sort(int start, int end)
{
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n", start, mid, mid+1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    
        sort(start, mid);               /*循环进行divide，这里如果要调试的话，要输入s，调到下一个函数*/
        sort(mid+1, end);
        merge(start, mid, end);

        printf("merge (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n", start, mid, mid+1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    }
}

int main(void)
{
    sort(0, LEN-1);
    return 0;
}
