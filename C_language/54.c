/*
 * 開頭先確保是否為單一積木，接著用對稱的方式去取得所有偶數列的積木，最後再依照是否剩餘奇數列去判斷是否添加剩餘的積木。
 * 
 */





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){   
    int i,j,pos=0;
    int length = matrixColSize[0];
    int width = matrixSize;
    int* ans = malloc(sizeof(int)*(length*width));
    *returnSize = length*width;
    if(*returnSize==1) ans[0] = matrix[0][0];
    for(i=0;i<(width/2);i++){
        for(j=i;j<length-i;j++) ans[pos++] = matrix[i][j];
        for(j=i+1;j<width-i-1;j++) ans[pos++] = matrix[j][length-i-1];  
        for(j=length-i-1;j>i-1;j--) ans[pos++] = matrix[width-i-1][j];
        if(pos==(*returnSize)) break;
        for(j=width-i-2;j>i;j--) ans[pos++] = matrix[j][i]; 
        if(pos==(*returnSize)) break;
    }
    if(pos==(*returnSize)){
        return ans; 
    }else if(width==1){
        for(i=0;i<(length*width);i++) ans[pos++] = matrix[0][i];
    }else if(width%2==1 && pos!=(*returnSize)){
        for(j=i;j<length-i;j++) ans[pos++] = matrix[i][j];
    }
    


    return ans;
}