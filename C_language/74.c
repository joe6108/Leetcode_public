/*
 * 依照每個列(row)的首個目標去判斷目標值(target)大約落在哪個區間，找到之後再從該區間去逐個搜尋。
 *
 */

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize, n = matrixColSize[0], i, j;
    if(m==1){
        for(i=0;i<n;i++){
            if(matrix[0][i]==target) return true;
        }
    }else{
        for(i=1;i<m;i++){
            if(matrix[i][0]>target) break;
        }
        for(j=0;j<n;j++){
            if(matrix[i-1][j]==target) return true;
        }
    }
    return false;
}