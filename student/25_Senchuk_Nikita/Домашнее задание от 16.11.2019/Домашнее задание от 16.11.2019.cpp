#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct List {

	int value;

	List* next;

};

List* nfind1(List* list, int n) {

	List* k = list;

	int counter = 1;

	while (k->next != NULL) {
		counter++;
		k = k->next;
	}

	k = list;

	for (int i = 0; i < counter - n; i++) {
		k = k->next;
	}

	return k;

}

List* nfind2(List* list, int n) {

	List* k1 = list;
	List* k2 = list;

	for (int counter = 0; counter < n-1; counter++) {
		k2 = k2->next;
	}

	while (k2->next != NULL) {
		k1 = k1->next;
		k2 = k2->next;
	}

	return k1;

}

int nfind3(List* list, int n) {
	if (list->next == NULL) { return 1; }
	else { 
		int k = 1 + nfind3(list->next, n);
		if (k == n) {
			cout << list->value << endl;
			return NULL;
		}
		else { return k; }
	}
}

int* retbyind(int* matr, int line, int column, int n, int m) {
	int lines = (line - 1) * m;
	int columns = (column - 1);
	return (matr + lines + columns);
}

void printmatrix(int* matrix, int n, int m) {
	cout << "Your matrix:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << *(retbyind(matrix, i, j, n, m)) << " ";
		}
		cout << endl;
	}
}

int* summatrix(int* matrix1, int* matrix2, int n, int m) {

	int* c = (int*)malloc(sizeof(int) * n * n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			*retbyind(c, i, j, n, m) = *retbyind(matrix1, i, j, n, m) + *retbyind(matrix2, i, j, n, m);
		}
	}

	return c;

}

int* multmatrix(int* matrix1, int* matrix2, int n, int m, int l) {

	int* result = (int*)malloc((sizeof(int))*n*l); 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l; j++) {

			int elem = 0;

			for (int k = 1; k <= m; k++) {
				elem = elem + *(retbyind(matrix1, i, k, n, m)) * *(retbyind(matrix2, k, j, m, l));
			}

			*retbyind(result, i, j, n, l) = elem;

		}
	}

	return result;

}

void main() {

	List elem4;
	List elem3;
	List elem2;
	List elem1;

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = NULL;

	elem1.value = 5;
	elem2.value = 3;
	elem3.value = 6;
	elem4.value = 1;

	cout << (nfind1(&elem1, 4))->value << endl;
	cout << (nfind2(&elem1, 4))->value << endl;
	nfind3(&elem1, 4);

	FILE *Matrix1File, *Matrix2File;

	Matrix1File = fopen("Matrix1.txt", "r");
	Matrix2File = fopen("Matrix2.txt", "r");

	int n, m, l, p;
	fscanf(Matrix1File, "%d", &n);
	fscanf(Matrix1File, "%d", &m);
	fscanf(Matrix2File, "%d", &l);
	fscanf(Matrix2File, "%d", &p);

	int* matrix1 = (int*)malloc(sizeof(int) * n * m);
	int* matrix2 = (int*)malloc(sizeof(int) * l * p);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int elem1;
			fscanf(Matrix1File, "%d", &elem1);
			*retbyind(matrix1, i, j, n, m) = elem1;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= l; j++) {
			int elem2;
			fscanf(Matrix2File, "%d", &elem2);
			*retbyind(matrix2, i, j, l, p) = elem2;
		}
	}

	fclose(Matrix1File);
	fclose(Matrix2File);

	printmatrix(matrix1, n, m);
	printmatrix(matrix2, l, p);
/*
	int* sum = summatrix(matrix1, matrix2, n, m);
	printmatrix(sum, n, m);*/

	int* mult = multmatrix(matrix1, matrix2, n, m, p);	
	printmatrix(mult, n, p);

}