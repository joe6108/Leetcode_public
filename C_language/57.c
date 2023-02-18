/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int table[100001] = {0};
    int** ans = malloc(sizeof(int*)*(intervalsSize+newIntervalSize));
    int pos = 0;
    for(int i=0;i<intervalsSize;i++){
        for(int j=intervals[i][0];j<intervals[i][1];j++) table[j] = 1;
        if(intervals[i][0]==intervals[i][1] && table[intervals[i][0]]==0) table[intervals[i][0]] = 2;
    }
    // new
    for(int j=newInterval[0];j<newInterval[1];j++) table[j] = 1;
    if(newInterval[0]==newInterval[1] && table[newInterval[0]]==0) table[newInterval[0]] = 2;

    for(int i=0;i<100001;i++){
        if(table[i]==1){
            ans[pos] = malloc(sizeof(int)*2);
            ans[pos][0] = i;
            while(i<100001 && table[i]==1) i++;
            ans[pos++][1] = i;
        }else if(table[i]==2){
            ans[pos] = malloc(sizeof(int)*2);
            ans[pos][0] = i;
            ans[pos++][1] = i;
        }
    }
    *returnSize = pos;
    *returnColumnSizes = malloc(sizeof(int)*pos);
    for(int i=0;i<pos;i++){
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}