/* A Mazing Problem */

#include <iostream>
#include <cstdlib>

#define MAX_ARRAY_COL 500
#define MAX_ARRAY_ROW 500
#define MAX_STACK_SIZE 500

typedef struct offsets {
    int vert;
    int horiz;
} Offsets;

Offsets move[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

typedef struct element {
  short int row;
  short int col;
  short int dir;
} Element;

int main(void) {
  int row, col;
  int currentRow, currentCol, currentDir;
  int nextRow, nextCol;
  int exitRow, exitCol;
  int found = 0;
  int top;
  int maze[MAX_ARRAY_ROW][MAX_ARRAY_COL] = {0};
  int mark[MAX_ARRAY_ROW][MAX_ARRAY_COL] = {0};
  Element stack[MAX_STACK_SIZE];
  Element walk;

  scanf("%d %d", &row, &col);
  exitRow = row, exitCol = col;

  for (int i = 0; i < row + 2; i++) {
    for (int j = 0; j < col + 2; j++) {
      if (i == 0 || i == (row + 1) || j == 0 || j == (col + 1))
        maze[i][j] = 1;
      else
        scanf("%d", &maze[i][j]);
    }
  }

  mark[1][1] = 1;
  top = 1;
  stack[0].row = 1;
  stack[0].col = 1;
  stack[0].dir = 0;

  while (top > -1 && found != 1) {
    top--;

    walk.row = stack[top].row;
    walk.col = stack[top].col;
    walk.dir = stack[top].dir;

    currentRow = walk.row;
    currentCol = walk.col;
    currentDir = walk.dir;

    while (currentDir < 4 && found != 1) {
      nextRow = currentRow + move[currentDir].vert;
      nextCol = currentCol + move[currentDir].horiz;

      if (nextRow == exitRow && nextCol == exitCol) {
        mark[nextRow][nextCol] = 1;

        stack[top].row = currentRow;
        stack[top].col = currentCol;
        stack[top].dir = currentDir;

        found = 1;

        for (int i = 0; i <= top; i++) {
          printf("(%d,%d) ", stack[i].row - 1, stack[i].col - 1);
        }
        printf("(%d,%d)\n", row - 1, col - 1);
      }   
      
      if (maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0) {
        mark[nextRow][nextCol] = 1;

        walk.row = nextRow;
        walk.col = nextCol;
        walk.dir = currentDir++;

        top++;

        stack[top - 1].row = currentRow;
        stack[top - 1].col = currentCol;
        stack[top - 1].dir = currentDir;

        currentRow = nextRow;
        currentCol = nextCol;
        currentDir = 0;
      } else {
        currentDir++;
      }
    }
  }

  if (top == -1) {
    printf("Can't reach the exit!\n");
  }

  return 0;
}