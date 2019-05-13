/* maze.h */
#ifndef MAZE_H
#define MAZE_H

#include "main.h"

extern int maze[MAX_ROW][MAX_COL];
void print_maze(void);

#endif

/*注意print_maze 的声明可以不加extern,而maze 的声明必须加extern*/