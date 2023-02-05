/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare( const void *arg1, const void *arg2 ){
    return *(int*)arg1 - *(int*)arg2;
}
void repeat_lookup(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int sum, int n, int*** ans, int* max, int index, int* table){
    sum+=candidates[index];
    if(sum == target || sum < target){
        table[n++] = candidates[index];
        // decide == target?
        if(sum == target){
            (*returnColumnSizes)[*returnSize] = n;
            (*ans)[*returnSize] = (int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                (*ans)[*returnSize][j] = table[j];
            }
            (*returnSize) += 1;
            // limit return array's buffer 
            if((*returnSize) == (*max)){
                (*max)*=2;
                int** tmp = realloc((*ans), sizeof(int*)*(*max));
                if(tmp==NULL){
                    printf("memory realloc fail\n");
                }
                (*ans) = tmp;
                int* tmp2 = realloc((*returnColumnSizes), sizeof(int)*(*max));
                if(tmp2==NULL){
                    printf("memory realloc fail\n");
                }
                (*returnColumnSizes) = tmp2;
            }
        }else{
            for(int i=index+1;i<candidatesSize;i++){
                if(i!=index+1 && candidates[i]==candidates[i-1]) continue;
                repeat_lookup(candidates,candidatesSize,target,returnSize,returnColumnSizes,sum,n,ans,max,i,table);
            }
        }
        
    }else{
        return;
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int sum=0,max=16,n=0;
    int table[30];
    *returnSize = 0;
    int** ans = (int**)malloc(sizeof(int*)*max);
    *returnColumnSizes = (int*)malloc(sizeof(int)*max);
    for(int i=0;i<candidatesSize;i++){
        if(i!=0 && candidates[i]==candidates[i-1]) continue;
        repeat_lookup(candidates,candidatesSize,target,returnSize,returnColumnSizes,sum,n,&ans,&max,i,table);
    }
    return ans;
}