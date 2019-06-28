Use:
`gcc -Wall -std=c99 matrix.c driver.c -o driver.exe && driver.exe`
to compile me and run!


Make sure you test your functions in the driver.c each time you implement them. Also make sure you test with non-square matrices.

Tasks:
1. Implement createMatrix for RANDOM matrixType. Look for how to create a random number in C online. --> DONE
2. Implement flipVertical.
3. Implement flipHorizontal.
4. Implement copyMatrix. Re-use createMatrix
5. Implement createMatrix for IDENTITY matrixType. You can levarage emptyOutMatrix() function.
6. Implement inverseMatrix.
7. Implement rotateLeft. Follow similar steps to inverseMatrix.
8. Implement rotateRight. Follow similar steps to inverseMatrix.
