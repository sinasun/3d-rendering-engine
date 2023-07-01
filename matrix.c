#include "matrix.h"

void printMatrix(int matrix[ROWS][COLS]) {
  printf("\nRotational matrix\n{");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void matrixMultiplication(int firstMatrix[][COLS], int secondMatrix[][COLS],
                          int resultMatrix[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      for (int k = 0; k < COLS; k++) {
        resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
      }
    }
  }
}

void matrices(int a, int b, int c) {
  int x[ROWS][COLS] = {{1, 0, 0}, {0, cos(a), -sin(a)}, {0, sin(a), cos(a)}};

  int y[ROWS][COLS] = {{cos(b), 0, sin(b)}, {0, 1, 0}, {-sin(b), 0, cos(b)}};

  int z[ROWS][COLS] = {{cos(c), -sin(c), 0}, {sin(c), cos(c), 0}, {0, 0, 1}};

  // store the result
  int result[ROWS][COLS];

  matrixMultiplication(x, y, result);
  matrixMultiplication(result, z, result);

  printMatrix(result);
}
