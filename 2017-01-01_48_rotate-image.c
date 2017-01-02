void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int** newMatrix = (int**)malloc(sizeof(int *) * matrixRowSize);
    for (int i = 0; i < matrixRowSize; i++) {
        newMatrix[i] = (int*)malloc(sizeof(int) * matrixColSize);
    }
    printf("Width: %i, Height: %i\n",matrixRowSize,matrixColSize);
    
    // iterate!
    for (int x = 0; x < matrixRowSize; x++) {
        for (int y = 0; y < matrixColSize; y++) {
            // matrix multiplication
            /*
                | 0 1 | * |x| = |x'| => x' = y
                |-1 0 |   |y|   |y'| => y' = -x
                
                then translate (n - 1) units upwards
                to make sure image is aligned properly
            */
            int newX = y;
            int newY = matrixRowSize - x - 1;
            printf("from: (%i,%i): %i\n", x,y,matrix[x][y]);
            newMatrix[newX][newY] = matrix[x][y];
            printf("to:   (%i,%i): %i\n", newX, newY,newMatrix[newX][newY]);
        }
    }
    
    // now, we need to copy that to the original.
    for (int x = 0; x < matrixRowSize; x++) {
        for (int y = 0; y < matrixColSize; y++) {
            matrix[x][y] = newMatrix[x][y];
        }
    }
}
