/* main.h */

#ifndef MAIN_H
#define MAIN_H

typedef struct point {int row, col;} item_t;    //定义一个名字

#define MAX_ROW 5
#define MAX_COL 5       

#endif

//在main.h 中定义了一个类型和两个常量;
//main.c、stack.c和maze.c都要用到这些定义,都要包含这个头文件。
