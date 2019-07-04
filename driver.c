#include<stdio.h>
#include "matrix.h"

void testFlipHorizontal();

int main(void){
    printf("Entered the program\n");
    

    testFlipHorizontal();
   
    // printf("After printMatrix m\n");

    // flipVertical(m);
    // printMatrix(m);
    // printf("After printMatrix and flipVertical\n");

    

    // fillRow (m, 1, 1);
    // printMatrix(m);
    // printf("After printMatrix and fillRow\n");

    // fillCol (m, 1, 2);
    // printMatrix(m);
    // printf("After printMatrix and fillCol\n");

    // matrix *n;
    // n = copyMatrix(m);
    // printMatrix(n);

    // // matrix* idSq = createMatrix(4, 4, IDENTITY);
    // // printMatrix(idSq);
    // // matrix* id = createMatrix(3, 7, IDENTITY);
    // // printMatrix(id);

    // printMatrix(m);
    // inverseMatrix(m);
    // printMatrix(m);

    // inverseMatrix(m);
    // printMatrix(m);

    // matrix* z = createMatrix(2,6, EMPTY);
    // z->val[0][0] = 0;
    // z->val[0][1] = 1;
    // z->val[0][2] = 2;
    // z->val[0][3] = 3;
    // z->val[0][4] = 4;
    // z->val[0][5] = 5;
    // printMatrix(z);
    // rotateLeft(z);
    // printMatrix(z);

    // matrix *random = createMatrix(2,8,RANDOM);
    // printMatrix(random);

    printf("Done!\n");

    //destroyMatrix(m);
    return 0;
}

void testFlipHorizontal(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    flipHorizontal(m);
    printf("After flipHorizontal:\n");
    printMatrix(m);
    destroyMatrix(m);
}