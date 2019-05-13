/*
*   广度优先搜索  
*   项目1介绍： 路径搜索
*       (1) 广度优先是一种步步为营的策略,每次都从各个方向探索一步,将前线推进一步,
*       (2) 队列中的元素总是由前线的点组成的
*       (3) 广度优先搜索还有一个特点是可以找到从起点到终点的最短路径
*       (4)而深度优先搜索找到的不一定是最短路径
*/
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5


struct point { int row, clo, predecessor; } queue[512];     //stack[512];
int head = 0, tail = 0;                                       //int top = 0;

void enqueue (struct point p)
{
    queue[tail] = p;
    tail++;
}
// void push (struct point p)
// {
//     stack[top] = p;
//     top++;
// }

struct point dequeue(void)
{
   head++;
   return queue[head-1];
}
// struct point pop(void)
// {
//    top --;
//    return stack[top];
// }

int is_empty(void)
{
    return head == tail;
}

// /*用predecessor这个新的数据结构保存走迷宫的路线*/
// struct point predecessor[MAX_ROW][MAX_COL] = {      /* ,每个走过的点都有一个前趋(Predecessor)的点 */
//     {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
//     {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
//     {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
//     {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
//     {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
// };

int maze[MAX_ROW][MAX_COL] = {      /*这个定义了一个二维的数组*/
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

/*已经走过的点在maze数组中记为2防止重复走*/
void visit(int row, int col)
{
    struct point visit_point = {row, col, head-1};  /*变量赋初值*/
    maze[row][col] = 2;
    enqueue(visit_point);
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
    struct point p = {0, 0, -1 };
    maze[p.row][p.clo] = 2;     /*maze[0][0] = 2;代表数组赋值,表示第一个点已经走过*/
    
    /*change*/
    enqueue(p);         //push(p);

    while(!is_empty()){
        p = dequeue();          //p = pop();
        if(p.row == MAX_ROW - 1 && p.clo == MAX_COL - 1)    /* goal */
            break;
        if(p.clo+1 < MAX_COL && maze[p.row][p.clo+1] == 0)    /* right */
            visit(p.row, p.clo+1);
        if(p.row+1 < MAX_ROW && maze[p.row+1][p.clo] == 0)    /* down */
            visit(p.row+1, p.clo);
        if(p.clo-1 >= 0 && maze[p.row][p.clo-1] == 0)    /* left */
            visit(p.row, p.clo-1);
        if(p.row-1 >= 0 && maze[p.row-1][p.clo] == 0)    /* up */
            visit(p.row-1, p.clo);
        print_maze();
    }
    if (p.row == MAX_ROW-1 && p.clo == MAX_COL-1){
        printf("(%d, %d)\n", p.row, p.clo);
        while(p.predecessor != -1){
            p = queue[p.predecessor];
            printf("(%d, %d)\n", p.row, p.clo);
        }
    }else
        printf("No path!\n");
    
    return 0;
}