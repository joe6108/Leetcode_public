/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int l,r;
    int* ans = NULL;
    *returnSize = 0;
    for(l=0;l<numsSize-1;l++){
        for(r=l+1;r<numsSize;r++){
            if(nums[l]+nums[r]==target){
                ans = malloc(sizeof(int)*2);
                *returnSize = 2;
                ans[0] = l;
                ans[1] = r;
                return ans;
            }
            if(nums[numsSize-l-1]+nums[numsSize-r-1]==target){
                ans = malloc(sizeof(int)*2);
                *returnSize = 2;
                ans[0] = numsSize-l-1;
                ans[1] = numsSize-r-1;
                return ans;
            }
        }
    }
    return ans;
}