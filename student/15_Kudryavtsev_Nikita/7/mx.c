#include <stdio.h>
#include <stdlib.h>

float** ReadNewMatrixInCurrentFile(int i1, int j1, FILE* file) {
    float **p;
    p = malloc(sizeof(float) * i1);

    for (int i = 0; i < i1; i++) {
        p[i] = malloc(sizeof(float)*j1);
    }

    for (int j = 0; j < j1; j++) {
        for (int i = 0; i < i1; i++) {
            fscanf(file, "%f", p[i] + j);
            printf("%f ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return p;
}

int main() {
    int i1, j1, i2, j2;
    FILE* file;
    file = fopen("mx.txt", "r");
    fscanf(file, "%d", &i1);
    fscanf(file, "%d", &j1);
    fscanf(file, "%d", &i2);
    fscanf(file, "%d", &j2);
    printf("%dx%d and %dx%d\n\n", i1, j1, i2, j2);

    float **firstMat = ReadNewMatrixInCurrentFile(i1, j1, file);
    float **secondMat = ReadNewMatrixInCurrentFile(i2, j2, file);
    printf("============================================\n\n");
    if (i1 == i2 && j1 == j2) {
        printf("Addition: \n");
        for (int j = 0; j < j1; j++) {
            for (int i = 0; i < i1; i++) {
                printf("%f ", firstMat[i][j] + secondMat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else printf("Addition: matrix sizes are not equal\n\n");

    if (i1 == j2) {
        printf("Multiplication: \n");
        for (int j = 0; j < j1; j++) {
            for (int i = 0; i < i1; i++) {
                float value = 0;
                for (int n = 0; n < i1; n++) {
                    value += firstMat[n][j]*secondMat[i][n];
                }
                printf("%f ", value);
            }
            printf("\n");
        }
    } else printf("Multiplication: the number of columns of matrix a is not equal to the number of rows B\n");
    return 0;
}
