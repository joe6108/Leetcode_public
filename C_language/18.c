/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare( const void *arg1, const void *arg2 ){
    return *(int*)arg1 - *(int*)arg2;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    long sum; //答案有可能大於INT範圍。
    int l,r,tmp;
    int count = 3000; 
    int** ans = (int**)calloc(count, sizeof(int*));
    *returnColumnSizes = (int*)calloc(count, sizeof(int));
    *returnSize = 0;
    //排序
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i=0;i<numsSize-3;i++){
        //讓i值不會重複取得。
        if(i>0 && i<numsSize-3 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<numsSize-2;j++){
            //讓j值不會重複取得。
            if(j>i+1 && j<numsSize-2 && nums[j]==nums[j-1]) continue;
            l=j+1;
            r=numsSize-1;
            tmp = nums[i] + nums[j];
            while(l<r){
                sum = (long)tmp + (long)nums[l] + (long)nums[r];
                if(sum == target){
                    ans[*returnSize]=calloc(4, sizeof(int));
                    (*returnColumnSizes)[*returnSize] = 4;
                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[l];
                    ans[*returnSize][3] = nums[r];
                    *returnSize+=1;
                    while(l<r && nums[l+1]==nums[l]) l++;
                    while(l<r && nums[r-1]==nums[r]) r--;
                    l++;
                    r--;
                }else if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
        }
    }

    return ans;
}