#include<stdio.h>
#include "matrix.h"

int main(void){
    printf("Entered the program\n");
    matrix* m = createMatrix(4, 4, EMPTY);
    m->val[0][3] = 5;
    m->val[1][3] = 8;
    m->val[2][3] = 9;
    m->val[3][3] = 10;
    printMatrix(m);
    printf("After printMatrix m\n");
    // flipVertical(m);
    // printMatrix(m);
    // printf("After printMatrix and flipVertical\n");
    //does not enter in CopyMatrix
    matrix *n = copyMatrix(m);
    printMatrix(n);
    printf("After printMatrix n\n");

    destroyMatrix(m);
    destroyMatrix(n);
    return 0;
}