/*para_callback.c*/

#include "para_callback.h"

void repeat_three_times(callback_t f, void *para)
{
    f(para);    /*刚好组成了 say_hello(void *para) */
    f(para);
    f(para);
}