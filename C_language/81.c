bool search(int* nums, int numsSize, int target){
    int pos;
    if(target >= nums[0]){
        pos = 0;
        while(pos<numsSize && target>=nums[pos]){
            if(target==nums[pos]) return true;
            if(pos>0 && nums[pos]<nums[pos-1]) break;
            pos++;
        }
    }else{
        pos = numsSize-1;
        while(pos>0 && target<=nums[pos]){
            if(target==nums[pos]) return true;
            if(pos<numsSize-1 && nums[pos]>nums[pos+1]) break;
            pos--;
        }
    }
    return false;
}