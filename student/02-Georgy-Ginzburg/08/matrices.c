#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;

struct Matrix {
    int num_rows;
    int num_cols;
    float **values;
};

Matrix CreateMatrix(float **vals, int num_rows, int num_cols);

Matrix MatrixAddition(Matrix m1, Matrix m2);

void PrintMatrix(Matrix m);

float **ReadArrayFromFile(FILE *fp, int num_rows, int num_cols);

Matrix MatrixMultiplication(Matrix m1, Matrix m2);

int main() {
    FILE *file1 = fopen("/home/ginzburggeorgy/programming/au"
                        "-2019-c-cpp/student/02-Georgy-Ginzburg/08/matrix1.txt", "r");
    FILE *file2 = fopen("/home/ginzburggeorgy/programming/au"
                        "-2019-c-cpp/student/02-Georgy-Ginzburg/08/matrix2.txt", "r");

    if (file1 == NULL || file2 == NULL) {
        printf("COULD NOT READ ONE OF THE FILES\n");
        return 0;
    }

    int n1, m1, n2, m2;
    fscanf(file1, "%d", &n1);
    fscanf(file1, "%d", &m1);
    fscanf(file2, "%d", &n2);
    fscanf(file2, "%d", &m2);
    printf("Provided matrix dimensions are: (%d,%d) and (%d,%d) \n\n", n1, m1, n2, m2);

    Matrix mat1 = CreateMatrix(ReadArrayFromFile(file1, n1, m1), n1, m1);
    PrintMatrix(mat1);
    Matrix mat2 = CreateMatrix(ReadArrayFromFile(file2, n2, m2), n2, m2);
    PrintMatrix(mat2);
    printf("\n");
    printf("Matrix sum: \n");
    PrintMatrix(MatrixAddition(mat1, mat2));

    printf("Matrix product: \n");
    PrintMatrix(MatrixMultiplication(mat1, mat2));
    return 0;
}

void PrintMatrix(Matrix m) {
    for (int i = 0; i < m.num_rows; i++) {
        for (int j = 0; j < m.num_cols; j++) {
            printf("%f ", m.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix CreateMatrix(float **vals, int num_rows, int num_cols) {
    Matrix temp;
    temp.num_rows = num_rows;
    temp.num_cols = num_cols;
    temp.values = vals;
    return temp;
}

float **ReadArrayFromFile(FILE *fp, int num_rows, int num_cols) {

    float **vals = calloc(num_rows, sizeof(float));

    for (int i = 0; i < num_cols; i++) {
        vals[i] = calloc(num_cols, sizeof(float));
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            fscanf(fp, "%f", *(vals + i) + j);

        }
    }
    return vals;
}

Matrix MatrixAddition(Matrix m1, Matrix m2) {
    int num_rows, num_cols;
    num_rows = m1.num_rows;
    num_cols = m1.num_cols;
    Matrix temp;
    float **vals = calloc(num_rows, sizeof(float));
    for (int i = 0; i < num_rows; i++) {
        vals[i] = calloc(num_cols, sizeof(float));
    }

    if (m1.num_rows != m2.num_rows && m1.num_cols != m2.num_cols) {
        temp = (Matrix) {-1, -1, vals};
        return temp;
    }

    temp = (Matrix) {num_rows, num_cols, vals};
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            temp.values[i][j] = m1.values[i][j] + m2.values[i][j];
        }
    }


    return temp;
}

Matrix MatrixMultiplication(Matrix m1, Matrix m2) {
    int num_rows, num_cols;
    num_rows = m1.num_rows;
    num_cols = m2.num_cols;

    Matrix temp;
    float **vals = calloc(num_rows, sizeof(float));
    for (int i = 0; i < num_rows; i++) {
        vals[i] = calloc(num_cols, sizeof(float));
    }

    if (m1.num_cols != m2.num_rows) {
        temp = (Matrix) {-1, -1, vals};
        return temp;
    }

    temp = (Matrix) {num_rows, num_cols, vals};

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {

            float scalar_product = 0;

            for (int k = 0; k < m1.num_cols; k++) {
                scalar_product += m1.values[i][k] * m2.values[k][j];
            }

            temp.values[i][j] = scalar_product;
        }
    }
    return temp;
}
