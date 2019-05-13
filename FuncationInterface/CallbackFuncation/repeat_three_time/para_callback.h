/* para_callback.h */

#ifndef PARA_CALLBACK_H
#define PARA_CALLBACK_H

typedef void (*callback_t)(void *);     //定义一个没有返回值的函数
extern void repeat_three_times(callback_t, void *);

#endif