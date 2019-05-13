/* generics.c */
#include "generics.h"

void *max(void *data[], int num, cmp_t cmp)
{
    int i;
    void *temp = data[0];   /*data[0]的首地址由temp来保存*/
    for(i=1; i<num; i++){
        if(cmp(temp, data[i])
    }
}