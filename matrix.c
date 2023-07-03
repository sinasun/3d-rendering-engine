#include "matrix.h"

void printMatrix(float matrix[ROWS][COLS]) {
  printf("\nRotational matrix\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void matrixMultiplication(float firstMatrix[][COLS], float secondMatrix[][COLS],
                          float resultMatrix[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      resultMatrix[i][j]= 0;
      for (int k = 0; k < COLS; k++) {
        resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
      }
    }
  }
}


void matrices(float a, float b, float c) {
  float x[ROWS][COLS] = {{1, 0, 0}, {0, cos(a), -sin(a)}, {0, sin(a), cos(a)}};

  float y[ROWS][COLS] = {{cos(b), 0, sin(b)}, {0, 1, 0}, {-sin(b), 0, cos(b)}};

  float z[ROWS][COLS] = {{cos(c), -sin(c), 0}, {sin(c), cos(c), 0}, {0, 0, 1}};

  // store the result
  float tempMatrix[ROWS][COLS];
  float resultMatrix[ROWS][COLS];

  matrixMultiplication(x, y, tempMatrix);
  
  matrixMultiplication(tempMatrix, z, resultMatrix);

  printMatrix(resultMatrix);
}
