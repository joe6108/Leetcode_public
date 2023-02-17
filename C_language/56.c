/*
 * 使用快速排列法之後，直接以雙雙一組去做合併的方式就完成了。
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void my_quicksort(int** intervals, int left, int right){
    if(left >= right) return;
    int l = left, r = right, pt = intervals[(left+right)/2][0];
    while(l<=r){
        while(intervals[l][0]<pt) l++;
        while(intervals[r][0]>pt) r--;
        if(l<=r){
            int t1, t2;
            t1 = intervals[l][0];
            t2 = intervals[l][1];
            intervals[l][0] = intervals[r][0];
            intervals[l][1] = intervals[r][1];
            intervals[r][0] = t1;
            intervals[r][1] = t2;
            l++;
            r--;
        }
    }
    if(left < r) my_quicksort(intervals,left,r);
    if(l < right) my_quicksort(intervals,l,right);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*intervalsSize);
    *returnColumnSizes = malloc(sizeof(int)*intervalsSize);
    *returnSize = 0;
    my_quicksort(intervals, 0, intervalsSize-1);
    
    for(int i=0;i<intervalsSize;i++){
        printf("[%d,%d] ", intervals[i][0], intervals[i][1]);
    }
    
    int i;
    for(i=0;i<intervalsSize;i++){
        if(i+1!=intervalsSize && intervals[i][1]>=intervals[i+1][0]){
            intervals[i+1][0] = intervals[i][0];
            if(intervals[i][1]>intervals[i+1][1]) intervals[i+1][1] = intervals[i][1];
        }else{
            ans[*returnSize] = malloc(sizeof(int)*2);
            (*returnColumnSizes)[*returnSize] = 2;
            ans[*returnSize][0] = intervals[i][0];
            ans[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    return ans;
}