/*
*   printf
*       (1) 符号转换说明
*/
#include <stdio.h>

int main(void)
{
    printf("%#x\n", 0xff);  // # -- 打印十六进制格式
    printf("%x\n", 0xff);
    printf("****************\n");

    printf("-%10s-\n", "hello");  // "-" 打印后的内容居左边，另外一边留出空格
    printf("-%-*s-\n",10, "hello");
    printf("****************\n");

    printf("%.4s\n", "hello"); //用一个整数表示精度,对于字符串来说指定了格式化后的长度
    printf("%6.4d-\n", 100);
    printf("-%*.*f-\n", 8, 4, 3.14);    // *.* = 8.4; 占8位，4位的精度
    printf("****************\n");
    
    printf("%hhd\n", 255);       // 对于整型参数可以指定字长hh , h, l, ll;结果是 -1， 吵了字节长度，首位为1， 当做负数的标识符
    printf("****************\n");   // 

    printf("main adress = %p\n", main);       // "p" 打印main函数的首地址
    printf("****************\n");  
    
    printf("double = %f\n", 3.14);  // double的精度
    printf("****************\n");   

    printf("指数形式＝　%e\n", 34344.14);   // 指数形式
    printf("指数形式＝　%E\n", 34444.14);   // 指数形式
    printf("****************\n");   

    printf("有效数字 = %g\n", 3.3205);   //打印有效数字
    printf("有效数字 = %g\n", 0.10003235321);   //打印有效数字
    printf("****************\n");   

    printf("%%\n"); 
    while(1);

    return 0;
}