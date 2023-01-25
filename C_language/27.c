int removeElement(int* nums, int numsSize, int val){
    int left = 0, right = numsSize-1, sum = 0;
    if(numsSize == 0) return 0;
    while(left <= right){
        if(nums[left]==val){
            while(right > left){
                if(nums[right]!=val){
                    nums[left] = nums[right--];
                    sum++;
                    break;
                }
                right--;
            }
        }else{
            sum++;
        }
        left++;
    }
    return sum;
}