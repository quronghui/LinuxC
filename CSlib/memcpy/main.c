/*  memcpy and memmove
*   (1) Comparision strcpy and strncpy
*   (2) 
*/
#include <stdio.h>
#include <string.h>

void *memmove(void *dest, const void *src, size_t n)
{
    char temp[n];
    int i;
    char *d = dest;
    const char *s = src;

    for (i = 0; i < n; i++)
        temp[i] = s[i];
    for (i = 0; i < n; i++)
        d[i] = temp[i];    
    
    return dest;
}

int main()
{
    char buf[20] = "hello word\n";  /* including '\0' */
    
    //memcpy(buf+1, buf, 13);
    char *buff = memmove(buf+1, buf, 13);
    printf(buff);
    //printf("%s\n", memmove(buf+1, buf, 13));
    // void (*func)(void *, const void *, size_t ) = memmove();
    // printf(func(buf+1, buf, 13));
    return 0;
}