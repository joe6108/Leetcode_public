/*
 * 最終版本 100最快了，相較v2，只是把頂部和左側的值預先給予，讓程式無須再判斷是否邊界了。
 */

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int table[m][n];
    table[0][0] = grid[0][0];
    for(int i=1;i<m;i++) table[i][0] = table[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++) table[0][j] = table[0][j-1] + grid[0][j];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(table[i-1][j]<table[i][j-1]){
                table[i][j] = table[i-1][j] + grid[i][j];
            }else{
                table[i][j] = table[i][j-1] + grid[i][j];
            }
        }
    }
    return table[m-1][n-1];
}


/*
 * v1 跑太久
 */

void repeat(int** grid, int m, int n, int y, int x, int sum, int* target){
    sum+=grid[y][x];
    if(y==m && x==n){
        if(sum < (*target) || (*target)==-1) (*target) = sum;
        return;
    }else if(sum < (*target) || (*target)==-1){
        if(y<m) repeat(grid, m, n, y+1, x, sum, target);
        if(x<n) repeat(grid, m, n, y, x+1, sum, target);
    }
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0], target = -1;
    repeat(grid, m-1, n-1, 0, 0, 0, &target);
    return target;
}

/*
 * v2 已經可以的方式，但不夠快
 */
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int table[m][n];
    table[0][0] = grid[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            if(i>0&&j>0){
                if(table[i-1][j]<table[i][j-1]){
                    table[i][j] = table[i-1][j] + grid[i][j];
                }else{
                    table[i][j] = table[i][j-1] + grid[i][j];
                }
            }else{
                //printf("i = %d, j = %d\n", i, j);
                if(i>0) table[i][j] = table[i-1][j] + grid[i][j];
                if(j>0) table[i][j] = table[i][j-1] + grid[i][j];
                //printf("table[i][j] = %d\n", table[i][j]);
            }
        }
    }
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    */
    return table[m-1][n-1];
}


