#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t row;
    size_t col;
    double **matrix;
} Matrix;

Matrix createMatrix(int row, int col, double initVal) {
    Matrix m;

    if(row < 0 || col < 0) {
        printf("Matrix dimension cannot be negative!\n");
        exit(1);
    }

    if(row == 0 || col == 0) {
        printf("Matrix dimension cannot be zero!\n");
        exit(1);
    }

    m.row = row;
    m.col = col;

    m.matrix = (double **)malloc(row * sizeof(double *));
    if(m.matrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for(size_t i = 0; i < row; i++) {
        m.matrix[i] = (double *)malloc(col * sizeof(double));
        if(m.matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    for(size_t i = 0; i < row; i++) {
        for(size_t j = 0; j < col; j++) {
            m.matrix[i][j] = initVal;
        }
    }

    return m;
}

void setMatrixElementAt(Matrix *m, size_t i, size_t j, double value) {
    if(i >= m->row || j >= m->col) {
        printf("Index invalid.\n");
        exit(1);
    }

    m->matrix[i][j] = value;
}

double getMatrixElementAt(const Matrix *m, size_t i, size_t j) {
    if(i >= m->row || j >= m->col) {
        printf("Index invalid.\n");
        exit(1);
    }

    return m->matrix[i][j];
}

Matrix addMatrix(const Matrix *A, const Matrix *B) {
    if(A->row != B->row || A->col != B->col) {
        printf("Dimension is not match.\n");
        exit(1);
    }

    size_t rowResult = A->row;
    size_t colResult = A->col;

    Matrix result = createMatrix(rowResult, colResult, 0.0);

    for(size_t i = 0; i < rowResult; i++) {
        for(size_t j = 0; j < colResult; j++) {
            setMatrixElementAt(&result, i, j, getMatrixElementAt(A, i, j) + getMatrixElementAt(B, i, j));
        }
    }

    return result;
}

Matrix subtractMatrix(const Matrix *A, const Matrix *B) {
    if(A->row != B->row || A->col != B->col) {
        printf("Dimension is not match.\n");
        exit(1);
    }

    size_t rowResult = A->row;
    size_t colResult = A->col;

    Matrix result = createMatrix(rowResult, colResult, 0.0);

    for(size_t i = 0; i < rowResult; i++) {
        for(size_t j = 0; j < colResult; j++) {
            setMatrixElementAt(&result, i, j, getMatrixElementAt(A, i, j) - getMatrixElementAt(B, i, j));
        }
    }

    return result;
}

Matrix multiplyMatrix(const Matrix *A, const Matrix *B) {
    if(A->col != B->row) {
        printf("Dimension is not match.\n");
        exit(1);
    }

    size_t rowResult = A->row;
    size_t colResult = B->col;

    Matrix result = createMatrix(rowResult, colResult, 0.0);

    for(size_t i = 0; i < rowResult; i++) {
        for(size_t j = 0; j < colResult; j++) {
            double sum = 0.0;
            for(size_t k = 0; k < A->col; k++) {
                sum += (getMatrixElementAt(A, i, k) * getMatrixElementAt(B, k, j));
            }
            setMatrixElementAt(&result, i, j, sum);
        }
    }

    return result;
}

void deleteMatrix(Matrix *m) {
    for(size_t i = 0; i < m->row; i++) {
        free(m->matrix[i]);
        m->matrix[i] = NULL;
    }
    free(m->matrix);
    m->matrix = NULL;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    Matrix A = createMatrix(n, m, 0.0);

    for(size_t i = 0; i < A.row; i++) {
        for(size_t j = 0; j < A.col; j++) {
            double x;
            scanf("%lf", &x);
            setMatrixElementAt(&A, i, j, x);
        }
    }

    printf("\n");

    for(size_t i = 0; i < A.row; i++) {
        for(size_t j = 0; j < A.col; j++) {
            printf("%10.3f ", getMatrixElementAt(&A, i, j));
        }
        printf("\n");
    }
}