#ifndef MATRIX
#define MATRIX

typedef struct {
    int** val;
    int width;
    int height;
} matrix;

enum matrixType {
    EMPTY, // Filled with 0s
    IDENTITY, // Filled with 0s except for 1s in the diagonal
    RANDOM // Filled with random positive numbers between 0 and 100.
};

/* Create a matrix of the given type with the specified width and height.*/
matrix* createMatrix(int height, int width, enum matrixType type);

void printMatrix(matrix* m);

void destroyMatrix(matrix* m);

// Creates a deep copy
matrix* copyMatrix(matrix* m);

// Fills the all the elements in the rowToFill with the given value.
void fillRow(matrix* m, int rowToFill, int value);

// Fills the all the elements in the colToFill with the given value.
void fillCol(matrix* m, int colToFill, int value);
/*
0 1      ->  1 0
2 3          3 2
4 4          4 4
*/
void flipVertical(matrix* m);
/*
0 1      ->  4 4
2 3          2 3
4 4          0 1
*/
void flipHorizontal(matrix* m);

// Inverts the matrix across it's TopLeft - BottomRight diagonal.
/*
0 1 2    ->     0 3
3 4 5           1 4
                2 5

1. Copy m so we don't lose it's values - we'll still need these
2. Free m's vals (using freeMatrixInternal) - we'll be changing its dimensions. We need to free before we allocate again otherwise we'll introduce a memory leak.
3. Change m's width and height.
4. Allocate m's vals using the new width and height (using allocMatrixInternal). At this point m vals are garbage so we still need to set them.
5. Fill m's values properly referencing the copied matrix.
6. Destroy the copied matrix using destroyMatrix so we don't introduce a memory leak.
*/
void inverseMatrix(matrix* m);


// Rotations..


/*
0 1 2    ->    2 5
3 4 5          1 4
               0 3
*/
void rotateLeft(matrix* m);

/*
0 1 2    ->    3 0
3 4 5          4 1
               5 2
*/
void rotateRight(matrix* m);
#endif