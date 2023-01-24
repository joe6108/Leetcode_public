int removeDuplicates(int* nums, int numsSize){
    if(numsSize==1) return 1;
    int sum = 1, stat = 1;
    for(int pos=1;pos<numsSize;pos++){ 
        if(nums[pos]!=nums[pos-1]){ 
            nums[stat++] = nums[pos];
            sum++;
        }
    }
    return sum;
}

