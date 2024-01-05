/*
 * 結果
 * Runtime : 100ms Beats 70.84%of users with C
 * Memory  : 22.92MB Beats 23.59%of users with C
 */
/*
 * 解題思路
 * 顛倒再顛倒顛倒就是答案了
 */

void swap(int* nums, int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void rotate(int* nums, int numsSize, int k) {
    k%=numsSize;
    int temp = 0;
    if(k>0){
        for(int i=0;i<numsSize/2;i++){
            swap(nums, i, numsSize-i-1);
        }
        for(int i=0;i<k/2;i++){
            swap(nums, i, k-i-1);
        }
        for(int i=k;i<(numsSize+k)/2;i++){
            printf("i = %d, another = %d\n", i, numsSize - i + k - 1);
            swap(nums, i, numsSize - i + k - 1);
        }
    }
}