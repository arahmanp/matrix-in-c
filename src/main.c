#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix A = createMatrix(2, 2, 2.5);

    for(int i = 0; i < A.row; i++) {
        for(int j = 0; j < A.col; j++) {
            printf("%.2f ", getMatrixElementAt(&A, i, j));
        }
        printf("\n");
    }

    deleteMatrix(&A);
}