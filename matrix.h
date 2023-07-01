#ifndef MATRIX_H
#define MATRIX_H

// #include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void matrixMultiplication(int firstMatrix[][COLS], int secondMatrix[][COLS], int resultMatrix[][COLS]);
void matrices(int a, int b, int c);
void printMatrix(int matrix[ROWS][COLS]);

#endif