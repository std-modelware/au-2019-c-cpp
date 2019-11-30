#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int n;
	FILE *S3;
	S3 = fopen("S3.txt", "r");
	fscanf(S3, "%d", &n);
	int m = n;
	int const n1 = 4;
	int const m1 = 4;
	int masA[n1][m1];
	int masB[n1][m1];
	int masC[n1][m1];
	int masD[n1][m1];
	FILE *S1, *S2;
	int x, y;
	S1 = fopen("S1.txt", "r");
	S2 = fopen("S2.txt", "r");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(S1,"%d",&x);
			fscanf(S2,"%d",&y);
			masA[i][j] = x;
			masB[i][j] = y;
			masC[i][j] = masA[i][j] + masB[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			masD[i][j] = 0;
			for (int k = 0; k < n; k++) {
				masD[i][j] += masA[i][k]*masB[k][j];
			}
		}
	}
	fclose(S1);
	fclose(S2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", masC[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", masD[i][j]);
		}
		printf("\n");
	}
}