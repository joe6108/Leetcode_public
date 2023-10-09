/*
 * 這題是非常簡單的一題題目，只要兩層for迴圈就能解決了。
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */ 

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*numRows);
    (*returnColumnSizes) = malloc(sizeof(int)*numRows);
    *returnSize = numRows;
    for(int i=0;i<numRows;i++){
        ans[i] = malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = (i+1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for(int j=0;j<(i-1);j++) ans[i][j+1] = ans[i-1][j] + ans[i-1][j+1];
    }
    return ans;
}