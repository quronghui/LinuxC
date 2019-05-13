# LinuxC Code
+ [Linux 一站式学习的代码学习笔记](https://quronghui.github.io)
+ [Code link](https://github.com/quronghui/LinuxC.git)

[TOC]



## Struct 

### struct.cpp

```
/*
*   本节将以结构体为例来讲解数据类型的组合和抽象。
*   1. 项目描述：通过结构体定义复数
        （1）直角坐标系：由实部和虚部组成
        （2）极坐标系：由模和幅角组成
*   2. 项目描述：将结构体当做函数的参数和返回值来传递
        （1）结构体当做函数的参数，比如 int main,中的int
        (2) struct complex_struct 当做函数 add_complex的参数
*/
```

### Data Abstraction.cpp

1. 代码编译：

   ```
   gcc　-*.c -lm		// 需要链接 libm.so 库
   ```

2. 函数框架

   ```
   /*
   *   数据抽像
   *   1. 项目描述：提供一个完整的调用方式，关于复数
           （1）直角坐标系：由实部和虚部组成
           （2）极坐标系：由模和幅角组成
   *   2. 代码分块：（1）结构体定义正常；
                  （2） 复数的基础存储，#include "PluralStorage.cpp" 
                  （3） 复数的运算， #include "PluralCalculate.cpp"
   */
   ```

3. 将复数运算的代码分成块的时候，报重复定义的错

   ```
   为了避免其他文件引用DataAbstraction.h，造成重复定义的问题：
   	add code:
   		#ifndef _TEST_H_ 
   		#define _TEST_H_  
   		{	...  }
   		#endif
   ```

4. 当增加枚举类型的标志位时，如何调用？

   ```
   // 枚举类型：枚举类型的成员和变量名在同一个空间，不能定义成同样的名字。
   enum coordinate_type        // 类似于Struct的Tag,enum代表的是枚举类型
   {                           // 代表常量Rectangular（直角坐标） == 0 ；
       Rectangular, Polar      // 代表常量Polar(极坐标) == 1
   };
   ```

### DataFlag.cpp

+ ```
  /*
  *   数据类型的标志位
  *   1. 项目描述：枚举类型的结构体，输出的结果是一个递增的常量
  */
  ```

## Array

### array.cpp

+ ```
  /*
  *   数组应用实例
  *   1. 项目描述：统计随机数中 0-9 出现的次数
          （1） rand() % 10, 生成随机数0-9
          （2） 统计出现的次数
          (3)随机数是均匀的
  */
  ```

### MulArray.cpp

+ ```
  /*
  *   数组应用实例
  *   1. 项目描述：设计一个剪刀石头布的游戏
          （1） srand 设定一个随机数的初始值，根据初始值做运算；
          （2） 当存在用户输入是，要对用户的输入进行一个判断，得出简单的结果
          （3） 判断输赢的机制 result = (man - computer + 4)%3 -1;
  */
  ```


## GDB

### AddRang.cpp

```
/*
*   项目介绍：Gdb单步调试和跟踪函数调用
        测试gdb的单步调试调试命令。
*/
```

### Breakpoint.cpp

```
/*
*   项目介绍：G/*
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
```

## Order

### InsertOrder.cpp

```
/*
*   插入排序
*   项目1介绍：
*        (1)扑克，插入牌的思想，和前面的一一比较；
*        (2)和之前的双重for循环不同
*        (3)策略：每次添加一个到已排序的子序列中，时间复杂度是 O(n^2)
*/
```

### DivideAndConquer

```
/*
*   归并排序
*   项目2介绍：
*       (1)相比较于插入排序策略：每次添加一个到已排序的子序列中，时间复杂度是 O(n^2)
*       (2)将时间复杂度降到 O(nlgn)。
*       (3)Gdb: 展开的方式看递归（这样很笨） -- 单步加断点的方式调试程序的每步结果。
*       (4)     捉住 Base Case 和 递推关系来理解，不能展开来看，这样就很乱了。
*/
```

### HalfFold.cpp

```
/*
*   折半查找
*   项目1介绍：
*        (1)折半查找的前提是数组已经排序好；
*       （2）提供assert代码测试的思想
*/
```

## Stack

### stack.cpp

```
/*
*   堆栈程序的测试  
*   项目1介绍： 用堆栈实现倒序打印
*        (1) 所有元素类型相同: 堆栈的存储：可以用数组实现;访问操作：通过函数接口提供
*/
```

### DeepSearch.cpp

```
/*
*   深度优先搜索  
*   项目1介绍： 路径搜索
*       (1) 这次堆栈里的元素是结构体类型的,用来表示迷宫中一个点的x和y座标。
*       (2) 我们用一个新的数据结构保存走迷宫的路线;用predecessor这个新的数据结构保存走迷宫的路线
*       (3) 已经走过的点在maze数组中记为2防止重复;
*       (4) 最后找到终点时，根据predecessor数组保存的路线从终点打印到起点。
*/
```

## Queue

### ExtentSearch.cpp

```
/*
*   广度优先搜索  
*   项目1介绍： 路径搜索
*       (1) 广度优先是一种步步为营的策略,每次都从各个方向探索一步,将前线推进一步,
*       (2) 队列中的元素总是由前线的点组成的
*       (3) 广度优先搜索还有一个特点是可以找到从起点到终点的最短路径
*       (4)而深度优先搜索找到的不一定是最短路径
*/
```

## Operator

### rule.cpp

```
/*
*   运算符规则
*   项目1介绍： 运算符的优先级顺序
×       （1）逻辑运算符的优先级，低于算数，移位，关系，相等性运算符的
*/
```

### Displacement.cpp

```
/*
*   移位运算
*   项目1介绍： 估计是类型转转换的时候发生了溢出的现象
*        0xcffffff3 >> 2 = 33fffffc
*        i>>2 = f3fffffc  ; 为啥左边多了两个1
*/
```

## x86

### hello.cpp

```
/*
*   汇编语言的学习
*   
*/
```

## LINK

### 函数

```
/*
*   堆栈程序的拆分
*   项目1介绍： 
*		(1)拆分为不同的函数；
*		(2)讲解函数间的调用关系
*        
*/
```

## Makefile

```
/*
*   深度优先搜索  
*   项目1介绍： 通过makefiles进行编译
*		(1)编写Makefile的规则进行make编译
*/
```

## Pointer

### pointer.c

```
/*
*   指针的参数和返回值
*/
```

### main.c

```
/* 
*   main 原型参数 :
*/
```

### array.c

```
/* 多维数组
*       (1)通过指向数组的指针，表示二维数组；
*       (2)实现数组的自增和赋值作用
*/
```

## FuncationInterface

### parameter

```
/*
*   传入参数和传出参数
*       结论：单层指针是不能分配存储空间的，所以是NULL
*/
```

### TwoPointer

```
/*
*   两层指针:可以动态分配存储空间
*/
```

### ReturnPointer

```
/*
*   返回值是指针的情况
*       (1)这个程序的运行结果是Sunday Monday吗?
*       (2)结果：为啥返回结果都是 Sunday，Sunday
*/
```

###  CallbackFuncation

#### GenericsAlgorithm

```
/*
*   回调函数的一个典型应用就是实现类似C++的泛型算法(Generics Algorithm)
*       (1)从任意数组中找出最大值；
*       (2)实现者不知道如何去比较，调用者需要提供一个作比较早作的回调函数
*/
```

#### repeat_three_time

```
/*
*   回调函数
*       实现了一个repeat_three_times 函数,可以把调用者传来的任何回调函数执行三次
*       调用者：提供函数组合后的操作方式（打印，排序）
*/
```

## CSLib

### fgetc.c

```
/*
*   fgetc and getchar
*   fputc and putchar
*       (1) 通过C标准库函数向文件中写入字符，并且读取字符
*       (2) 从终端输入时有两种方法表示文件结束 ctrl+D
*/
```

## FILE and io

### read_and_write

1.  blocking_read_terminal.c

   ```
   /*
   *   blocking_read_terminal.c
   *   1) Shell进程创建a.out 进程,a.out 进程开始执行,而Shell进程睡眠等待a.out 进程退出。
   *   2)a.out 调用read 时睡眠等待,直到终端设备输入了换行符才从read 返回,read只读走10个
   *     字符,剩下的字符仍然保存在内核的终端设备输入缓冲区中。
   *   3) a.out 进程打印并退出,这时Shell进程恢复运行,Shell继续从终端读取用户输入的命令,
   */
   ```

2. Unblocking_read_terminal.c

   ```
   /*
   *   Unblocking_read_terminal.c
   *   1) 只有读终端，才会造成阻塞。
   *   2) 通过设置open的参数flags = O_NONBLOCK,控制其防阻塞
   */
   ```

### ioctl

### file status flag

1. file_status_flag.c

   ```
   /*
   *   file_status_flag.c
   *   !)通过函数fcntl函数，实现对终端文件参数的设置，实现O_NONBLOCK，实现非阻塞
   *   2)函数的主体还是和Unblocking_read_terminal.c 一致
   */
   ```

2. cmd_flag.c

   ```
   /*
   *   cmd_flag.c
   *   1) 以下程序通过命令行的第一个参数指定一个文件描述符,
   *   2) 利用shell重定向功能在该描述符上打开文件；
   */
   ```

## FILE system

+ 看笔记

## Process

```
/*
*   fork.c
*   1) parent and child tranfor process
*/
/*
*   exec.c
*   1),第一个"ps" 是程序名,execlp函数要在PATH环境变量中找到这个程序并执行它
*   2),而第二个"ps" 是第一个命令行参数,execlp函数并不关心它的值,只是简单地把它传给ps 程序,
*/
/*
*    pipe.c   
*	1)管道
*/
/*
*   upper.c
*   1) 转换小写位大写
*/
```

## Signal

```
$ 代码没有实现，一直在报错
/*
*   blood signal.c
*   
*/

/*
*   Infinite loop.c
*   1)死循环
*/

/*
*   mysleep.c 
*   1) 
*/
```

## Pthread

1. pthread_create.c

   ```
   /*
   *   pthread_create()
   *   1)get the process pid and thread tid
   */
   ```

2. pthread_metux.c

   ```
   /*
   *   pthread_metux.c
   *   1)防止冲突:在线程访问内存数据的时候
   */
   ```

3. ```
   /*
   *   pthread_con.c
   *   condition variable
   *   1) 通过条件变量(Condition Variable)来阻塞等待一个条件,或者唤醒等待这个条件的线程.
   */
   
   /*
   *   pthread_exit()
   *   1) three ways for exit thread
   */
   ```

## Socket

### TCP

1. server

   ```
   /*
   *   server.c
   *   1)是从客户端读字符,然后将每个字符转换为大写并回送给客户端；
   *   2)server 只能满足单个client的一次请求；
   *   3)server -- 单个client的多次请求：将应答写在while(1)中；
   *   4)server -- fork(); 处理多个client的请求
   *   5)在同一个终端，关闭server后，还能重新开启server
   */
   
   /*
   *   select_server.c
   *   1)select是网络程序中很常用的一个系统调用,它可以同时监听多个阻塞的文件描述符
   *   2)不需要fork和多进程就可以实现并发服务的server。
   *   3) 未使用
   */
   ```

2. client

   ```
   /*
   *   client.c
   *   1)是从命令行参数中获得一个字符串发给服务器,
   *     然后接收服务器返回的字符串并打印。
   */
   /* client_interactive.c 
   *   1) client and server 交互式进行应答
   */
   ```

3. wrap

   ```
   /*
   *   wrap.c
   *   1)把与socket相关的一些系统函数加上错误处理代码包装成新的函数,做成一个模块wrap.c:
   *   2)依赖文件wrap也要编译成wrap.o库文件；而不是编译成可执行文件;一直报错，未声明使用
   */
   ```

### UDP

1. server

   ```
   /*
   *   server.c
   *   1) UDP 过程中少了listen and accept
   *   2) 不用关闭文件描述符
   *   3) recvfrom error: Transport endpoint is not connected
   *      udp 中的采用的是数据报文，并非流 SOCK_STREAM --> SOCK_DGRAM 
   */
   ```

2. client

   ```
   /*
   *   client.c
   *   1)  SOCK_STREAM --> SOCK_DGRAM
   *   2) UDP 不用考虑多个client的链接
   ×       不用考虑同意终端关闭server后不能重新开启的现象
   */
   ```

   

