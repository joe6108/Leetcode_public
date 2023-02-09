/*
觀察旋轉後的陣列，可以從index中推出只要將每行的順序倒過來，再依照對角的數字做交換就能完成。
*/


void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,temp;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<(matrixSize/2);j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = temp;
        }
    }
    for(i=0;i<matrixSize-1;i++){
        for(j=0;j<(matrixSize-i-1);j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize-1-j][matrixSize-1-i];
            matrix[matrixSize-1-j][matrixSize-1-i] = temp;
        }
    }
}