#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

// Static functions are only visibile in the file in which they're declared

// Zero-s out all of the matri'x vals
static void emptyOutMatrix(matrix* m);
// Creates a matrix with random values
static void randomOutMatrix (matrix *m);
// Allocates memory for m->val based on m->width and m->height
static void allocMatrixInternal(matrix* m);
// Free all space associated with m->val
static void freeMatrixInternal(matrix* m);

matrix* createMatrix(int height, int width, enum matrixType type) {
    matrix* m = malloc(sizeof(matrix));
    m->width = width;
    m->height = height;
    allocMatrixInternal(m);

    switch(type) {
        case EMPTY:
            emptyOutMatrix(m);
            break;
        case IDENTITY:
            // TODO:
            break;
        case RANDOM:
            randomOutMatrix (m);
            break;
        default:
            break;
    }
    return m;
}

void printMatrix(matrix* m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", m->val[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void destroyMatrix(matrix* m) {

}

void fillRow(matrix* m, int rowToFill, int value) {

}

void fillCol(matrix* m, int colToFill, int value) {

}

static void freeMatrixInternal(matrix* m){
    for (int i = 0; i < m->width; i++) {
        free(m->val[i]);
    }
    free(m->val);
}

static void allocMatrixInternal(matrix* m){
    m->val = (int**) malloc(m->width * sizeof(int));
    for (int i = 0; i < m->width; i++) {
        m->val[i] = (int*) malloc(m->height * sizeof(int));
    }
}

static void emptyOutMatrix(matrix* m) {
    printf("Entered emptyOutMatrix\n"); 
    printf("m->height = %d, m->width = %d\n", m->height, m->width); 
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            m->val[i][j] = 0;
        }
    }
    printf("Done with emptyOutMatrix\n"); 
}

static void randomOutMatrix (matrix *m){
    printf("Entered randomOutMatrix\n");
    //Uses the current time to generate seed
    srand(time(0));
    for (int i = 0; i< m->height; i++){
        for (int j = 0; j< m->width; j++){
            m->val[i][j] = rand();
        }
    }
    printf("Done with randomOutMatrix\n"); 
}

/*
0 1      ->  1 0
2 3          3 2
4 4          4 4
*/
void flipVertical(matrix* m){
    printf("Entered flipVertical\n");
    //Uses the current time to generate seed
    for (int i = 0; i< m->height; i++){
        for (int j = 0; j< m->width; j++){
            //duplicates the last column
            m->val[i][j]  = m->val[i][m->width-(j+1)] ; 
            //TODO: Fix
        }
        
        
    }
    printf("Done with flipVertical\n");

}

matrix* copyMatrix(matrix* m){
    printf("Entered copyMatrix\n");
    matrix *n = createMatrix(m->height, m->width, type);
    printf("Done with copyMatrix\n");
    return n;
}