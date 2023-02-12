int maxSubArray(int* nums, int numsSize){
    int max;
    int i,j,sum;
    if(numsSize==0) return 0;
    sum = nums[0];
    max = nums[0];
    for(i=1;i<numsSize;i++){
        if(sum>0 && sum){
            sum +=nums[i];
        }else{
            sum = nums[i];
        }
        if(sum > max) max = sum;
    }
    return max;
}