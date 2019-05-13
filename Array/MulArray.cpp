/*
*   数组应用实例
*   1. 项目描述：设计一个剪刀石头布的游戏
        （1） srand 设定一个随机数的初始值，根据初始值做运算；
        （2） 当存在用户输入是，要对用户的输入进行一个判断，得出简单的结果
        （3） 判断输赢的机制 result = (man - computer + 4)%3 -1;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char gesture[3][10] = {"scissor", "stone", "cloth"};    // 字符串数组，优化代码结构
    int man, computer, result, ret;

    srand(time(NULL));                                  ////srand 函数指定一个seed,调用当前系统时间距离1970年1月1日00:00:00的秒钟数，然后传给srand.
    while(1){
        computer = rand() % 3;                          // 上限为3的数：0，1,2
        printf("\nInput you gesture(scissor--0, stone--1, cloth--2)\n");
        ret = scanf("%d", &man);

        // 为了给用户输入做一个判断
        if (ret != 1 || man < 0 || man > 2) {
            printf("Invalid input! Please input 0,1 or 2.\n");
            continue;                       // 跳出本次循环，重头开始进行下一次循环
        }

        printf("Your gesture: %s\tComputer's gesture: %s\n", gesture[man], gesture[computer]);
        
        result = (man - computer + 4)%3 -1;
        if(result > 0)
            printf("you win!\n");
        else if (result == 0)
            printf("Draw!\n");
        else
            printf("Your lose!\n");
    }
    
    return 0;

}
