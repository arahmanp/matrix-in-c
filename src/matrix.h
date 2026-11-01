#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
    size_t row;
    size_t col;
    double **matrix;
} Matrix;

Matrix createMatrix(int row, int col, double initVal);
void deleteMatrix(Matrix *m);

void setMatrixElementAt(Matrix *m, size_t i, size_t j, double value);
double getMatrixElementAt(const Matrix *m, size_t i, size_t j);

Matrix addMatrix(const Matrix *A, const Matrix *B);
Matrix subtractMatrix(const Matrix *A, const Matrix *B);
Matrix multiplyMatrix(const Matrix *A, const Matrix *B);

#endif