int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1]==1) return 0;
    int i,j,key=1;
    for(i=0;i<obstacleGridSize;i++){
        if(obstacleGrid[i][0]==1) key = 0;
        obstacleGrid[i][0] = key;
    }
    key = 1;
    for(j=1;j<obstacleGridColSize[0];j++){
        if(obstacleGrid[0][j]==1) key = 0;
        obstacleGrid[0][j] = key;
    }
    for(i=1;i<obstacleGridSize;i++){
        for(j=1;j<obstacleGridColSize[0];j++){
            if(obstacleGrid[i][j]==1){
                obstacleGrid[i][j] = 0;
            }else{
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1];
}