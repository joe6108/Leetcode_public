int repeat_search(int* nums, int numsSize, bool* table, int sum){
    //printf("sum = %d\n", sum);
    if(sum>=(numsSize-1)){
        return 1;
    }else{
        if(!table[sum]){
            table[sum] = true;
            for(int i=nums[sum];i>0;i--){
                //printf("change sum = %d, nums[sum] = %d\n", sum+i, nums[sum]);
                if(repeat_search(nums, numsSize, table, sum+i)) return 1;
            }
        }
    }
    return 0;
}
bool canJump(int* nums, int numsSize){
    bool* table = malloc(sizeof(bool)*numsSize);
    memset(table, false, sizeof(bool)*numsSize);
    if(numsSize==1) return true;
    int i, sum;
    table[0] = true;
    for(i=nums[0];i>0;i--){
        if(repeat_search(nums, numsSize, table, i)) return true;
    }
    return false;
}