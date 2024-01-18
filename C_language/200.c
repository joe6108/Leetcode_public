/*
 * 結果
 * Runtime : 21ms Beats 50.82%of users with C
 * Memory  : 9.93MB Beats 26.64%of users with C
 */
/*
 * 解題思路
 * 這題我是使用暴力破解的方式解決問題，我直接建立一個Table，用來確定相對應的位置是否有使用過，
 * 然後透過檢查所有位置，只要找到任何一個1(島嶼)，就判斷找到一塊島嶼，並從這個位置開始，將所
 * 有相鄰的1都找出來，並視為使用過(因為是同一塊島嶼)，接著就能確保一塊島嶼(含邊界)都使用過，
 * 接著只要再從未使用過的開始找，是否有其他島嶼，再以此類推即可。
 */

void lookup(char** grid, int gridSize, int* gridColSize, bool** dp, int x, int y){
    //printf("x = %d, y = %d\n", x, y);
    if(x<0 || y<0) return;
    for(int i=x;i<gridSize;i++){
        for(int j=y;j<gridColSize[0];j++){
            if(dp[i][j] == false){
                dp[i][j] = true;
                if(grid[i][j] == '1'){
                    //printf("i=%d, j=%d\n", i, j);
                    lookup(grid, gridSize, gridColSize, dp, i+1, j);
                    lookup(grid, gridSize, gridColSize, dp, i-1, j);
                    lookup(grid, gridSize, gridColSize, dp, i, j-1);
                    lookup(grid, gridSize, gridColSize, dp, i, j+1);
                }else{
                    return;
                }
            }else{
                return;
            }
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    bool** dp = malloc(sizeof(bool*)*gridSize);
    for(int i=0;i<gridSize;i++)
        dp[i] = calloc(gridColSize[0], sizeof(bool));
    int total = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(dp[i][j] == false){
                if(grid[i][j] == '1'){
                    total++;
                    lookup(grid, gridSize, gridColSize, dp, i, j);
                }   
            }
        }
    }
    for(int i=0;i<gridSize;i++)
        free(dp[i]);
    free(dp);
    return total;
}