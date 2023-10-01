#pragma once
// #include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void matrixMultiplication(float firstMatrix[][COLS], float secondMatrix[][COLS],
                          float resultMatrix[][COLS]);
void matrices(float a, float b, float c, float objectMatrix[][COLS]);
void printMatrix(float matrix[ROWS][COLS]);
