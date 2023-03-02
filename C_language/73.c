/*
 * 製作一個table去同時紀錄被感染的位置，假如原本的位置就是感染源(0)就先不記錄這個位置，因為之後的for迴圈還是會跑到這個感染源。
 *
 */

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize, n = matrixColSize[0],i,j,k;
    bool table[m][n];
    memset(table, false, sizeof(bool)*m*n);    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(matrix[i][j]==0 && table[i][j]==false){
                table[i][j] = true;
                for(k=0;k<n;k++){
                    if(matrix[i][k]!=0){
                        table[i][k] = true;
                        matrix[i][k] = 0;
                    }
                }
                for(k=0;k<m;k++){
                    if(matrix[k][j]!=0){
                        table[k][j] = true;
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
}