/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main() {
	int  n, m, k;
	FILE *S1, *S2,*S3;
	int x,y;
	S1 = fopen("S1.txt", "r");
	S2 = fopen("S2.txt", "r");
	S3 = fopen("S3.txt", "r");
	fscanf(S3, "%d", &n);
	fscanf(S3, "%d", &m);
	fscanf(S3, "%d", &k);

	const int  n1 = 10;
	const int  m1 = 11;
	const int  k1 = 10;
	int masA[n1][m1];
	int masB[m1][k1];
	int masD[n1][k1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(S1, "%d", &x);
			masA[i][j] = x;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			fscanf(S2, "%d", &y);
			masB[i][j] = y;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			masD[i][j] = 0;
			for (int r = 0; r < m; r++) {
				masD[i][j] += masA[i][r] * masB[r][j];
			}
		}
	}
	fclose(S1);
	fclose(S2);
	fclose(S3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", masD[i][j]);
		}
		printf("\n");
	}
}*/