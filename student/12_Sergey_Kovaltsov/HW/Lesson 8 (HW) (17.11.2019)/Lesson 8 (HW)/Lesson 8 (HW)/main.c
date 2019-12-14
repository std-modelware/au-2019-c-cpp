#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrixcalc.h"

int main() {
	FILE *mat1, *mat2;
	mat1 = fopen("matrix1.txt", "r");
	matrix* matrix1 = NULL;
	matrix1 = fillmatrix(mat1);
	printmatrix(matrix1);
	fclose(mat1);

	mat2 = fopen("matrix2.txt", "r");
	matrix* matrix2 = NULL;
	matrix2 = fillmatrix(mat2);
	printmatrix(matrix2);

	fclose(mat2);

	matrix *matrix3 = NULL;
	matrix3 = matrixmult(matrix1, matrix2);
	printmatrix(matrix3);

	return 0;
}