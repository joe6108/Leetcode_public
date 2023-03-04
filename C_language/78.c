/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
 * 這題的道理同上一題的意思一樣，只是改變了限制的大小，但速度不夠快，相較最快的速度(0 ms)，我的方法至少也要(4 ms)才能解決。
 */
# define MaxSize 10000

int repeat(int level, int next, int Maxlevel, int* table, int** ans, int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(level==Maxlevel){
        ans[*returnSize] = malloc(sizeof(int)*Maxlevel);
        (*returnColumnSizes)[*returnSize] = Maxlevel;
        for(int i=0;i<Maxlevel;i++) ans[*returnSize][i] = table[i];
        (*returnSize)++;
        return;
    }
    for(int i=next;i<numsSize;i++){
        table[level] = nums[i];
        repeat(level+1, i+1, Maxlevel, table, ans, nums, numsSize, returnSize, returnColumnSizes);
    }
    
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int*)*MaxSize);
    (*returnColumnSizes) = malloc(sizeof(int)*MaxSize);
    (*returnColumnSizes)[0] = NULL;
    *returnSize = 1;
    int *table = malloc(sizeof(int)*numsSize);
    for(int i=1;i<=numsSize;i++) repeat(0, 0, i, table, ans, nums, numsSize, returnSize, returnColumnSizes);
    return ans;
}