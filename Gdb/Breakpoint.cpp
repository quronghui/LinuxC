/*
*   Gdb 调试的断点测试
*   项目1介绍：(1):首先从键盘读入一串数字存到字符数组input中,然后转换成整型存到sum;
*           (2)字符型转化为整形：整形＝字符型－‘０’的ASCII值
*           (3)ASCII码值：'0'＝48; '\0' = 0
*   项目2介绍: 断电测试
*           (1)将字符串Ａ倒装后，存储在字符串Ｂ里面
*           (2)Bug: 数组的末位含有一个　‘\0’字符，printf打印的时候遇到'\0'就停止打印
*   项目３介绍：段错误
            (1)由scanf函数的越界，造成的影响
*/
#include <stdio.h>

// int main(void)
// {

//     int sum = 0, i=0;
//     char input[5];

//     while(1){
//         sum = 0;                            //下一次的循环，初始化sum＝０
//         scanf("%s", input);      /* code */
//         for (i = 0; input[i] != '\0'; i++){
//             sum = sum*10 + input[i] - '\0';
//         }
//         printf("sum = %d\n", sum);
//     }
//     return 0;
// }

// /*项目２实现*/
// int main(void)
// {
//     int i;
//     char str[6] = "hello";
//     char reverse_str[6] = "";

//     printf("Output str = %s\n", str);
//     for( i = 0; i < 5; i++)
//         reverse_str[5-i] = str[i];                     
//     printf("Output reverse_str = %s\n", reverse_str);
//     return 0;  
// }

// /*项目３：段错误测试*/
// int main(void)
// {
//     int man = 0;
//     scanf("%d", man);           // man函数少了　'&'
//     printf("man = %d", man);        
//     return 0;
// }

/*项目３：段错误测试,为了测试scanf函数，这个函数是一个极其凶险的函数*/
int main(void)
{

    int sum = 0, i=0;
    char input[5];

    scanf("%s", input);      /* code */
    for (i = 0; input[i] != '\0'; i++){
        if (input[i] < '0' || input[i] > '9') {
            printf("Invaild input!\n");
            sum = -1;
            break;
        }
        sum = sum*10 + input[i] - '\0';
    }
    printf("sum = %d\n", sum);
    return 0;
}