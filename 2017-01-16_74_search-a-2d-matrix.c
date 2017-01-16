/**
* Search a 2D Matrix (#74)
* Runtime: 3 ms
*
* O(n + log(m)) runtime. Could arguably be made faster
* by binary searching the cols, but result is miniscule
*
* too many edge cases in the code tbh
*/
bool searchRow(int* row, int matrixRowSize, int target) {
    int low = 0;
    int high = matrixRowSize-1;
    int med;
    
    if (matrixRowSize < 1)
        return false;
    
    while (low <= high) {
        med = (low + high) / 2;
        if (row[med] > target)
            high = med - 1;
        else if (row[med] < target)
            low = med + 1;
        else {
            return true;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrixRowSize < 1 || matrixColSize < 1)
        return false;
    
    if (target < matrix[0][0] || target > matrix[matrixRowSize-1][matrixColSize-1])
        return false;
    
    if (matrixRowSize == 1)
        return searchRow(matrix[0],matrixColSize,target);
    
    int i = 0;
    while (i < matrixRowSize && matrix[i][0] <= target) {
        i++;
        if (i > matrixRowSize)
            return false;
    }    
    return searchRow(matrix[i-1],matrixColSize,target);
}
