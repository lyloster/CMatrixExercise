#include<stdio.h>
#include "matrix.h"

int main(void){
    printf("Entered the program\n");
    matrix* m = createMatrix(4, 4, EMPTY);

    // m->val[0][3] = 3;
    // m->val[1][2] = 9;
    // m->val[0][1] = 4;
    // m->val[0][0] = 2;
    // m->val[1][1] = 5;
    // m->val[1][3] = 8;
    // m->val[2][3] = 6;
    // m->val[3][3] = 1;

    printMatrix(m);
    printf("After printMatrix m\n");

    // flipVertical(m);
    // printMatrix(m);
    // printf("After printMatrix and flipVertical\n");

    // flipHorizontal(m);
    // printMatrix(m);
    // printf("After printMatrix and flipHorizontal\n");

    fillRow (m, 1, 1);
    printMatrix(m);
    printf("After printMatrix and fillRow\n");

    fillCol (m, 1, 2);
    printMatrix(m);
    printf("After printMatrix and fillCol\n");

    matrix *n;
    n = copyMatrix(m);
    printMatrix(n);

    matrix* idSq = createMatrix(4, 4, IDENTITY);
    printMatrix(idSq);
    matrix* id = createMatrix(3, 7, IDENTITY);
    printMatrix(id);

    inverseMatrix(m);
    printMatrix(m);

    // matrix* z = createMatrix(2,5, EMPTY);
    // z->val[0][0] = 0;
    // z->val[0][1] = 1;
    // z->val[0][2] = 2;
    // z->val[0][3] = 3;
    // z->val[0][4] = 4;
    // z->val[0][5] = 5;
    // printMatrix(z);
    // rotateLeft(z);
    // printMatrix(z);
    //destroyMatrix(m);
    return 0;
}