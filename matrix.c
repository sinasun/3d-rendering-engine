// #include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
  printf("\nresult\n{");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("}\n");
}


void matrixMultiplication(int x[ROWS][COLS], int y[ROWS][COLS], int z[ROWS][COLS]) {
  int r[ROWS][COLS];

  int temp[ROWS][COLS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < COLS; k++) {
        temp[i][j] += x[i][k] * y[k][j];
      }
    }
  }

  // multiple z and temp
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < COLS; k++) {
        r[i][j] += z[i][k] * temp[k][j];
      }
    }
  }

  printMatrix(r);
}



void matrices(int a, int b, int c) {
  int x[ROWS][COLS] = {{1, 0, 0}, {0, cos(a), -sin(a)}, {0, sin(a), cos(a)}};

  int y[ROWS][COLS] = {{cos(b), 0, sin(b)}, {0, 1, 0}, {-sin(b), 0, cos(b)}};

  int z[ROWS][COLS] = {{cos(c), -sin(c), 0}, {sin(c), cos(c), 0}, {0, 0, 1}};

  matrixMultiplication(x, y, z);
}

// int** allocateMatrix(int rows, int cols){

//   int **matrix= malloc(sizeof(int *)* rows);
  
//   for(int i=0; i<rows; i++){
//     matrix[i]= malloc(sizeof(int *)* cols);
//   }

//   return matrix;
// }
