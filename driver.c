#include<stdio.h>
#include "matrix.h"

int main(void){
    printf("Entered the program\n");
    matrix* m = createMatrix(4, 6, EMPTY);
    m->val[0][5] = 5;
    m->val[1][5] = 8;
    m->val[2][5] = 9;
    m->val[3][5] = 10;
    printMatrix(m);
    printf("After printMatrix\n");

    destroyMatrix(m);
    return 0;
}