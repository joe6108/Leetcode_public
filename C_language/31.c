void swap(int* nums, int i, int j){
    int tmp;
    tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}


void nextPermutation(int* nums, int numsSize){
    int i,pt,pt_index;
    for(i=numsSize-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            pt = nums[i-1];
            pt_index = i-1;
            break;
        }
    }
    if(i==0){
        for(i=0;i<numsSize/2;i++){
            swap(nums, i, numsSize-1-i);
        }
    }else{
        for(i=numsSize-1;i>pt_index;i--){
            if(nums[i]>pt){
                swap(nums, i, pt_index);
                break;
            }
        }
        for(i=0;i<(numsSize-1-pt_index)/2;i++){
            int j = pt_index+1+i;
            swap(nums, j, numsSize-1-i);
        }
    }
    return nums;
}