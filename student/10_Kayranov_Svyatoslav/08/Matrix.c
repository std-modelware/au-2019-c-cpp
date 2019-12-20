#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define n1 2
#define m1 2
#define n2 2
#define m2 2

int matrix1[n1][m1];
int matrix2[n2][m2];

void main() {
	int num = 0;
	FILE* file;
	if ((file = fopen("file.txt", "r")) == NULL) {
		printf("ERROR: Invalid file");
		return 1;
	}
	for (int n = 0; n < n1; n++) {
		for (int m = 0; m < m1; m++) {
			if (fscanf(file, "%d", &num) == EOF) {
				printf("Error: matrix1 reading error");
				return 1;
			}
			matrix1[n][m] = num;
		}
	}
	for (int n = 0; n < n2; n++) {
		for (int m = 0; m < m2; m++) {
			if (fscanf(file, "%d", &num) == EOF) {
				printf("Error: matrix2 reading error");
				return 1;
			}
			matrix2[n][m] = num;
		}
	}

	int matrixMultiply[n1][m2];
	int pointerN = 0;
	int pointerM = 0;

	for (int n = 0; n < n1; n++) {
		for (int m = 0; m < m2; m++) {
			matrixMultiply[n][m] = 0;
			for (int k = 0; k < max(n1, n2); k++) {
				matrixMultiply[n][m] += matrix1[n][m] * matrix2[n][m];
			}
		}
	}

	int matrixAddition[n1][m1];
	if ((n1 == n2) && (m1 == m2)) {
		for (int n = 0; n < n1; n++) {
			for (int m = 0; m < m2; m++) {
				matrixAddition[n][m] = matrix1[n][m] + matrix2[n][m];
			}
		}
	}
	return;
}

/*
	while ((c = getc(file)) != EOF) {
		if ((c != ' ') && (c != '\n')) {
			if (firstDigit < 1) {
				num = c;
				continue;
			}
			num = num * 10 + c;
		}
		else {
			if ((n1 * m1) <= mtxPointer) {
				matrix1[mtxPointer / m1][mtxPointer - (mtxPointer / m1)] = num;
				firstDigit = 0;
			}
			else {
				matrix2[mtxPointer / n1][mtxPointer - (mtxPointer / n1)] = num;
				firstDigit = 0;
			}
		}
	}

/*
	while ((c = getc(file)) != EOF) {
		if (((c == ' ') || (c == '\n')) && (flag == false)) {
			count++;
			continue;
		}
		else {
			a
		}
	}
	*/
	/*
		for (int i = 0; (((a[i] == ' ') || (a[i] == '/n')) && (count > 1)); i++) {
			if (count == 0) {
				n = a[i];
			}
			if (count == 1) {
				m = a[i];
			}
		}
	*/