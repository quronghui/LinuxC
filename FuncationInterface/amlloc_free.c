/* malloc_free.c
*   void * 可以喝任何指针类型之间相互式转化
*   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int number;
    char *msg;
}unit_t;

int main(void)
{
    unit_t *p = malloc(sizeof(unit_t)); /*void * 可以喝任何指针类型之间相互式转化*/
    if (p == NULL) {
        printf("out of memory\n");  /* 对每次的调用malloc，判断函数成功/失败的返回值 */
        exit(1);
    }
    p->number = 3;
    p->msg = malloc(20);
    strcpy(p->msg, "hello world!");
    printf("number: %d\nmsg: %s\n", p->number, p->msg);

    free(p->msg);   /* free(p);之后,p 所指的内存空间是归还了,但是p 的值并没有变;先释放里面的值 */
    free(p);    /*释放 p 指针*/
    p = NULL;   /* 为避免出现野指针,我们应该在free(p); 之后手动置p = NULL; */
    return 0;
}