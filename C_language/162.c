/*
 * 結果
 * Runtime : 0ms Beats 100.00%of users with C
 * Memory  : 6.62MB Beats 17.74%of users with C
 */
/*
 * 解題思路
 * 單純的先解決山在最左以及最右的問題之後，只要再判斷哪座山峰確定是山峰，再來比較就可以了。
 */

int findPeakElement(int* nums, int numsSize) {
    if(numsSize == 1) return 0;
    int ans = 0;
    for(int i=1;i<numsSize;i++){
        if(i==(numsSize-1)){
            if(nums[numsSize-2] < nums[i]){
                if(nums[ans] < nums[i]){
                    ans = i;
                }
            }
        }else{
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                if(nums[i] > nums[ans]) ans = i;
            }
        }
    }
    return ans;
}