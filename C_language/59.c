/* 
 * 第一步: 因為答案的大小已經固定，所以空間可以預先設好。
 * 第二步: 這題的目的是求Spiral Matrix I的輸入，也就是說我們可以用一樣的方式去慢慢放入相對應的位置
 * 首先，隨著index的增加，會發現每次增加時，都一定有個row或者column固定，這代表我們可以想像到能夠只用四個for迴圈就能跑完所有數字。
 * 依照上述邏輯，我總共會重複四個過程，固定row -> 固定column -> 固定row -> 固定column，重複這四個步驟。
 * 以3x3的例子來說，我就能夠像是: 12(row) -> 34(column) -> 56(row) -> 78(column) ， 就能夠完成所有輸入
 * 最後你會發現9不在了，但只要觀察一下，就會發現每次n=奇時，都只會有最後一個數字沒輸入到，所以只要特別注意這點，就能夠完成這題。
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*n);
    *returnColumnSizes = malloc(sizeof(int)*n);
    int pos = 1, i, j, k;
    for(i=0;i<n;i++){
        ans[i] = malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    for(j=0;j<n/2;j++){
        for(k=j;k<n-1-j;k++) ans[j][k] = pos++;
        for(k=j;k<n-1-j;k++) ans[k][n-1-j] = pos++;
        for(k=n-1-j;k>j;k--) ans[n-1-j][k] = pos++;
        for(k=n-1-j;k>j;k--) ans[k][j] = pos++;
    }
    if(n%2) ans[n/2][n/2] = pos;
    return ans;
}