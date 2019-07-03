#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define DEBUG 1

// Static functions are only visibile in the file in which they're declared

// Zero-s out all of the matri'x vals
static void emptyOutMatrix(matrix* m);
// Creates an identity-like matrix, works for all sizes
static void identityOutMatrix (matrix *m);
// Creates a matrix with random values
static void randomOutMatrix (matrix *m);
// Allocates memory for m->val based on m->width and m->height
static void allocMatrixInternal(matrix* m);
// Free all space associated with m->val
static void freeMatrixInternal(matrix* m);
// Swaps the places of two integers
static void swap(int *a, int *b);

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
            identityOutMatrix(m);
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
    if (DEBUG){
        printf("Entered fillRow\n"); 
    }
    for (int j = 0; j<m->width; j++){
        m->val[rowToFill][j] = value;
    }
    if (DEBUG){
        printf("Done with fillRow\n");
    }   
}

void fillCol(matrix* m, int colToFill, int value) {
    if (DEBUG){
        printf("Entered fillCol\n"); 
    }
    for (int j = 0; j<m->height; j++){
        m->val[j][colToFill] = value;
    }
    if (DEBUG){
        printf("Done with fillCol\n");
    }   
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
    if (DEBUG){
        printf("Entered emptyOutMatrix\n"); 
    } 
    printf("m->height = %d, m->width = %d\n", m->height, m->width); 
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            m->val[i][j] = 0;
        }
    }
    if (DEBUG){
        printf("Done with emptyOutMatrix\n");
    }
}

static void identityOutMatrix (matrix *m){
    if (DEBUG){
        printf("Entered identityOutMatrix\n"); 
    }  
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            if (i==j){
                m->val[i][j] = 1;
            }else{
               m->val[i][j] = 0; 
            }
        }
    }
    if (DEBUG){
        printf("Done with identityOutMatrix\n");
    }
}

static void randomOutMatrix (matrix *m){
    if (DEBUG){
        printf("Entered randomOutMatrix\n"); 
    }
    //Uses the current time to generate seed
    srand(time(0));
    for (int i = 0; i< m->height; i++){
        for (int j = 0; j< m->width; j++){
            m->val[i][j] = rand();
        }
    }
    if (DEBUG){
        printf("Done with randomOutMatrix\n"); 
    }
}

/*
0 1      ->  1 0
2 3          3 2
4 4          4 4
*/
void flipVertical(matrix* m){
    if (DEBUG){
        printf("Entered flipVertical\n"); 
    }
    for (int i = 0; i< m->height; i++){
        for (int j = 0; j< m->width/2; j++){
           swap(&m->val[i][j], &m->val[i][(m->width)-(j+1)]) ; 
        }
    }
    if (DEBUG){
        printf("Done with flipVertical\n");
    }  
}

void flipHorizontal(matrix* m){
    if (DEBUG){
        printf("Entered flipHorizontal\n"); 
    }
    for (int i = 0; i< m->width; i++){
        for (int j = 0; j< m->height/2; j++){
           swap(&m->val[j][i], &m->val[(m->height)-(j+1)][i]) ; 
        }
    }
    if (DEBUG){
        printf("Done with flipHorizontal\n");
    }  
}
static void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

matrix* copyMatrix(matrix* m){
    if (DEBUG){
        printf("Entered copyMatrix\n"); 
    }
    matrix* n = malloc(sizeof(matrix));
    n->width = m->width;
    n->height = m->height;
    allocMatrixInternal(n);
    for (int i = 0; i< m->height; i++){
        for (int j = 0; j< m->width; j++){
           n->val[i][j] = m->val[i][j] ; 
        }
    }
    if (DEBUG){
        printf("Done with copyMatrix\n");
    }  
    return n;
 }

/*1. Copy m so we don't lose it's values - we'll still need these
2. Free m's vals (using freeMatrixInternal) - we'll be changing its dimensions. We need to free before we allocate again otherwise we'll introduce a memory leak.
3. Change m's width and height.
4. Allocate m's vals using the new width and height (using allocMatrixInternal). At this point m vals are garbage so we still need to set them.
5. Fill m's values properly referencing the copied matrix.
6. Destroy the copied matrix using destroyMatrix so we don't introduce a memory leak.
*/
void inverseMatrix(matrix* m){
    if (DEBUG){
        printf("Entered inverseMatrix\n"); 
    } 

    matrix *n = copyMatrix(m);
    freeMatrixInternal(m);
    int temp = m->width;
    m->width = m->height;
    m->height = temp;
    allocMatrixInternal(m);
    for (int i = 0; i<m->width; i++){
        for(int j = 0; j<m->height; j++){
            m->val[i][j] = n->val[j][i];
        }
    }

    if (DEBUG){
            printf("Done with inverseMatrix\n"); 
    } 
}



// Rotations..


/*
0 1 2    ->    2 5
3 4 5          1 4
               0 3
*/
// void rotateLeft(matrix* m){
//     if (DEBUG){
//         printf("Entered rotateLeft\n"); 
//     } 

//     inverseMatrix(m);
//     for(int i = 0; i<m->width/2; i++){
//         swap(&m->val[i], &m->val[(m->width)]);
        
//     }

//     if (DEBUG){
//         printf("Done with rotateLeft\n"); 
//     }
// }