/*
*   深度优先搜索  
*   项目1介绍： 路径搜索
*       (1) 这次堆栈里的元素是结构体类型的,用来表示迷宫中一个点的x和y座标。
*       (2) 我们用一个新的数据结构保存走迷宫的路线;用predecessor这个新的数据结构保存走迷宫的路线
*       (3) 已经走过的点在maze数组中记为2防止重复;
*       (4) 最后找到终点时，根据predecessor数组保存的路线从终点打印到起点。
*/
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5


struct point { int row, clo; } stack[512];
int top = 0;

void push (struct point p)
{
    stack[top] = p;
    top++;
}

struct point pop(void)
{
   top --;
   return stack[top];
}

int is_empty(void)
{
    return top == 0;
}

/*用predecessor这个新的数据结构保存走迷宫的路线*/
struct point predecessor[MAX_ROW][MAX_COL] = {      /* ,每个走过的点都有一个前趋(Predecessor)的点 */
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};

int maze[MAX_ROW][MAX_COL] = {      /*这个定义了一个二维的数组*/
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

/*已经走过的点在maze数组中记为2防止重复走*/
void visit(int row, int col, struct point pre)
{
    struct point visit_point = {row, col};  /*变量赋初值*/
    maze[row][col] = 2;
    predecessor[row][col] = pre;            /* 没看懂这里赋初值是什么意思？ */
    push(visit_point);
}

void print_maze(void)
{
    int i, j;
    printf("maze array : =\n");
    for (i = 0; i < MAX_ROW; i++){
        for (j = 0; j < MAX_COL; j++)
            printf("%d ", maze[i][j]);
        putchar('\n');
    }
    printf("*****************\n");
}

int main(void)
{
    struct point p = {0, 0};
    maze[p.row][p.clo] = 2;     /*maze[0][0] = 2;代表数组赋值，还是代表二维数组*/
    push(p);

    while(!is_empty()){
        p = pop();
        if(p.row == MAX_ROW - 1 && p.clo == MAX_COL - 1)    /* goal */
            break;
        if(p.clo+1 < MAX_COL && maze[p.row][p.clo+1] == 0)    /* right */
            visit(p.row, p.clo+1, p);
        if(p.row+1 < MAX_ROW && maze[p.row+1][p.clo] == 0)    /* down */
            visit(p.row+1, p.clo, p);
        if(p.clo-1 >= 0 && maze[p.row][p.clo-1] == 0)    /* left */
            visit(p.row, p.clo-1, p);
        if(p.row-1 >= 0 && maze[p.row-1][p.clo] == 0)    /* up */
            visit(p.row-1, p.clo, p);
        print_maze();
    }
    if (p.row == MAX_ROW-1 && p.clo == MAX_COL-1){
        printf("(%d, %d)\n", p.row, p.clo);
        while(predecessor[p.row][p.clo].row != -1){
            p = predecessor[p.row][p.clo];
            printf("(%d, %d)\n", p.row, p.clo);
            
        }
        
    }else
        printf("No path!\n");
    
    return 0;
}