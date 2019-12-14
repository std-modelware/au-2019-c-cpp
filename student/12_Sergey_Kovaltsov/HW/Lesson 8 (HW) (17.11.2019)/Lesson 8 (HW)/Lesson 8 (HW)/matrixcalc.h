#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
	int x;
	int y;
	float data;
	struct matrix *right;
	struct matrix *down;
} matrix;


//Operations
matrix* fillmatrix(FILE *matrix_r);
matrix* matrixsumm(matrix* matrix_1, matrix* matrix_2);
matrix* matrixmult(matrix* matrix_1, matrix* matrix_2);

//Print
void printmatrix(matrix* pmatrix);