#include<stdio.h>
#include "matrix.h"

void testFlipHorizontal();
void testFlipVertical();
void testFillRow();
void testFillColumn();
void testCopyMatrix();
void testIdentityMatrix();
void testInverseMatrix();
void testRandomMatrix();
void testRotateLeft();
void testRotateRight();

int main(void){
    printf("Entered the program\n");
    testFlipHorizontal();
    testFlipVertical();
    testFillRow();
    testFillColumn();
    testCopyMatrix();
    testIdentityMatrix();
    testIdentityMatrix();
    testRandomMatrix();
    testRotateLeft();
    testRotateRight();
    printf("Done!\n");
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

void testFlipVertical (){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    flipVertical(m);
    printf("After flipVertical:\n");
    printMatrix(m);
    destroyMatrix(m);
}

void testFillRow(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    fillRow(m, 1, 2);
    printf("After fillRow:\n");
    printMatrix(m);
    destroyMatrix(m);
}

void testFillColumn(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    fillCol (m, 1, 2);
    printf("After fillCol:\n");
    printMatrix(m);
    destroyMatrix(m);
}

void testCopyMatrix(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    matrix *n;
    n = copyMatrix(m);
    printf("After copyMatrix:\n");
    printMatrix(n);
    destroyMatrix(m);
    destroyMatrix(n);
}

void testIdentityMatrix(){
    matrix* idSq = createMatrix(4, 4, IDENTITY);
    printf("Square identity matrix:\n");
    printMatrix(idSq);

    matrix* id = createMatrix(5, 3, IDENTITY);
    printf("Identity-like matrix:\n");
    printMatrix(id);

    destroyMatrix(idSq);
    destroyMatrix(id);
}

void testInverseMatrix(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    inverseMatrix(m);
    printf("After inverseMatrix:\n");
    printMatrix(m);
    destroyMatrix(m);
}

void testRandomMatrix(){
    matrix* rand = createMatrix(4, 4, RANDOM);
    printf("Random matrix:\n");
    printMatrix(rand);
    destroyMatrix(rand);
}

void testRotateLeft(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    printf("After ritateLeft:\n");
    rotateLeft(m);
    destroyMatrix(m);
}

void testRotateRight(){
    matrix* m = createMatrix(5, 4, RANDOM);
    printMatrix(m);
    printf("After ritateRight:\n");
    rotateRight(m);
    destroyMatrix(m);
}