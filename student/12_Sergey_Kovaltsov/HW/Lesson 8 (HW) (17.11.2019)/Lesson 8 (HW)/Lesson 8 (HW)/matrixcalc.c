#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "./matrixcalc.h"

static int ERROR = 0;
static matrix* root = NULL;
static matrix* moving = NULL;
static matrix* creation = NULL;

matrix* create_node() {
	matrix* mgen = (matrix*)malloc(sizeof(matrix));
	(*mgen).right = NULL;
	(*mgen).down = NULL;
	(*mgen).data = 0;
	return mgen;
}

void start_moving(matrix_a) {
	if (matrix_a != moving) {
		moving = matrix_a;
	}
} 

matrix* create_root() {
	root = create_node();
	moving = root;
	return root;
}

matrix* setemptymatrix(int i, int j) {
	static matrix* matlink = NULL;
	matlink = create_root();
	creation = moving;
	for (int k = i; k > 0; k--) {
		for (int l = j; l > 0; l--) {
			(*moving).y = j - l;
			if (l != j) {
				(*moving).down = create_node();
				moving = (*moving).down;
			}
			(*moving).x = i - k + 1;
			(*moving).data = 0;
		}
		(*moving).y = j;
		moving = creation;
		if (k != 1) {
			(*moving).right = create_node();
			moving = (*moving).right;
			creation = moving;
		}	
	}
	return matlink;
}

void add(matrix* matrix_a, int adress_x, int adress_y, float value) {
	start_moving(matrix_a);
	while ((*moving).x != adress_x) {
		moving = (*moving).right;
	}
	while ((*moving).y != adress_y) {
		moving = (*moving).down;
	}
	(*moving).data = value;
}

matrix* fillmatrix(FILE *matrix_r) {
	int x, y;
	fscanf(matrix_r, "%d", &x);
	fscanf(matrix_r, "%d", &y);
	matrix *new_mat = setemptymatrix(x, y);

	for (int a = 1; a <= y; a++)
	{
		for (int b = 1; b <= x; b++)
		{
			float m;
			fscanf(matrix_r, "%f", &m);
			add(new_mat, b, a, m);
		}
	}
	return new_mat;
}

float valcoord(matrix* matrix_1, int adress_x, int adress_y) {
	start_moving(matrix_1);
	while ((*moving).x != adress_x) {
		moving = (*moving).right;
	}
	while ((*moving).y != adress_y) {
		moving = (*moving).down;
	}
	return (*moving).data;
}

matrix* matrixsumm(matrix* matrix_1, matrix* matrix_2) {
	int x1, y1;
	int x2, y2;

	start_moving(matrix_1);
	while ((*moving).right != NULL) {
		moving = (*moving).right;
	}
	x1 = (*moving).x;
	while ((*moving).down != NULL) {
		moving = (*moving).down;
	}
	y1 = (*moving).y;

	start_moving(matrix_2);
	while ((*moving).right != NULL) {
		moving = (*moving).right;
	}
	x2 = (*moving).x;
	while ((*moving).down != NULL) {
		moving = (*moving).down;
	}
	y2 = (*moving).y;

	if (x1 != x2 || y1 != y2) {
		printf("Impossible!");
		exit(1);
	}

	matrix* summedmatrix = setemptymatrix(x1, y1);
	
	float ans1 = 0, ans2 = 0;
	for (int a = 1; a <= y1; a++){
		for (int b = 1; b <= x1; b++)
		{
			ans1 = valcoord(matrix_1, b, a);
			ans2 = valcoord(matrix_2, b, a);

			valcoord(summedmatrix, b, a);
			(*moving).data += (ans1 + ans2);
		}
	}
	

	return summedmatrix;
}

matrix* matrixmult(matrix* matrix_1, matrix* matrix_2) {
	int x1, y1;
	int x2, y2;

	start_moving(matrix_1);
	while ((*moving).right != NULL) {
		moving = (*moving).right;
	}
	x1 = (*moving).x;
	while ((*moving).down != NULL) {
		moving = (*moving).down;
	}
	y1 = (*moving).y;

	start_moving(matrix_2);
	while ((*moving).right != NULL) {
		moving = (*moving).right;
	}
	x2 = (*moving).x;
	while ((*moving).down != NULL) {
		moving = (*moving).down;
	}
	y2 = (*moving).y;

	if (x1 != y2 || y1 != x2) {
		printf("Impossoble!");
		exit(2);
	}

	matrix* multedmatrix = setemptymatrix(x2, y1);
	float ans1 = 0, ans2 = 0;

	for (int i = 1; i <= y1; i++) {
		for (int j = 1; j <= x2; j++) {
			for (int k = 1; k <= x1; k++) {
				ans1 = valcoord(matrix_1, k, i);
				ans2 = valcoord(matrix_2, j, k);
				valcoord(multedmatrix, j, i);
				(*moving).data += (ans1 * ans2);
			}
		}
	}
	return multedmatrix;
}

void printmatrix(matrix* pmatrix) {
	int x, y;
	start_moving(pmatrix);
	while ((*moving).right != NULL) {
		moving = (*moving).right;
	}
	x = (*moving).x;
	while ((*moving).down != NULL) {
		moving = (*moving).down;
	}
	y = (*moving).y;

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			printf("%f ", valcoord(pmatrix, j, i));
		}
		printf("\n");
	}
	printf("\n");
}