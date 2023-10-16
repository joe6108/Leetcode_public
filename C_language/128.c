/*
 * 先將陣列排列之後，再透過for迴圈去抓取最大連續數的量，雖然這方法的速度很快，但缺點是我不確定有沒有符合題目要的意思。
 */

int compare( const void *arg1, const void *arg2 ){
    return *( int* ) arg1 -  *( int* ) arg2;
}

int longestConsecutive(int* nums, int numsSize){
    if(numsSize==0) return 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int sum = 0, max = 0;
    for(int i=1;i<numsSize;i++){
        //printf("%d ", nums[i]);
        if(nums[i]==nums[i-1]) continue;
        if(nums[i]-nums[i-1]==1){
            sum++;
        }else{
            if(sum > max) max = sum;
            sum = 0;
        }
    }
    return sum > max ? sum+1 : max+1;
}