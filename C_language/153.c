/*
 * 結果
 * Runtime : 0 ms Beats 100.00% of users with C
 * Memory  : 6.46MB Beats 79.41% of users with C
 */

int findMin(int* nums, int numsSize) {
    for(int i=1;i<numsSize;i++){
        int temp_step = nums[i] - nums[i-1];
        if(temp_step < 0){
            return nums[i];
        }
    }
    return nums[0];
}