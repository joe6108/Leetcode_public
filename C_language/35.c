int searchInsert(int* nums, int numsSize, int target){
    int pos = 0;
    for(pos=0;pos<numsSize;pos++){
        if(nums[pos]==target){
            return pos;
        }else if(nums[pos] > target){
            return pos;
        }
    }
    return pos;
}