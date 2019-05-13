/*
*   深度优先搜索  
*   项目1介绍： 通过makefiles进行编译
*/
/* main.c */
#include <stdio.h>
#include "main.h"
#include "stack.h"
#include "maze.h"

/*用predecessor这个新的数据结构保存走迷宫的路线*/
struct point predecessor[MAX_ROW][MAX_COL] = {      /* ,每个走过的点都有一个前趋(Predecessor)的点 */
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
};

/*已经走过的点在maze数组中记为2防止重复走*/
void visit(int row, int col, struct point pre)
{
    struct point visit_point = {row, col};  /*变量赋初值*/
    maze[row][col] = 2;
    predecessor[row][col] = pre;            /* 没看懂这里赋初值是什么意思？ */
    push(visit_point);
}

int main(void)
{
    struct point p = {0, 0};
    maze[p.row][p.col] = 2;     /*maze[0][0] = 2;代表数组赋值，还是代表二维数组*/
    push(p);

    while(!is_empty()){
        p = pop();
        if(p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)    /* goal */
            break;
        if(p.col+1 < MAX_COL && maze[p.row][p.col+1] == 0)    /* right */
            visit(p.row, p.col+1, p);
        if(p.row+1 < MAX_ROW && maze[p.row+1][p.col] == 0)    /* down */
            visit(p.row+1, p.col, p);
        if(p.col-1 >= 0 && maze[p.row][p.col-1] == 0)    /* left */
            visit(p.row, p.col-1, p);
        if(p.row-1 >= 0 && maze[p.row-1][p.col] == 0)    /* up */
            visit(p.row-1, p.col, p);
        print_maze();
    }
    if (p.row == MAX_ROW-1 && p.col == MAX_COL-1){
        printf("(%d, %d)\n", p.row, p.col);
        while(predecessor[p.row][p.col].row != -1){
            p = predecessor[p.row][p.col];
            printf("(%d, %d)\n", p.row, p.col);
            
        }
        
    }else
        printf("No path!\n");
    
    return 0;
}