/* stack.h */
#ifndef STACK_H
#define STACK_H

#include "main.h"   /* provides definition for item_t  */
                    /* 其他文件的头文件，也包含在本函数的头文件中 */

extern void push(item_t);
extern item_t pop(void);
extern int is_empty(void);

#endif