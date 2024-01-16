/*
 * 結果
 * Runtime : 0ms Beats 100%of users with C
 * Memory  : 6.55MB Beats 43.06%of users with C
 */
/*
 * 解題思路
 * 使用DP的方式解決，DP用來記錄到每個位置(i)時的最大值為多少，最後的numsSize-1就會是答案。
 * 也就是說，i=0時是固定值，i=1時，判斷i=0 跟 i=1 誰大，i=2時，就會計算i=0+i=2的值，而因為相鄰的i=1不能相加，則
 * 將相加的值直接和i=1比較，決定當前最大值為多少，透過這樣的方式，不停決定出最大值就完成了。
 */

int rob(int* nums, int numsSize) {
    int max = 0, total = 0;
    int * ans = calloc(numsSize, sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(i==0){
            ans[i] = nums[i];
        }else if(i==1){
            ans[i] = nums[i];
            if(ans[0] > ans[i]) ans[i] = ans[0];
        }else{
            total = nums[i] + ans[i-2];
            ans[i] = total > ans[i-1] ? total : ans[i-1];
        }
    }
    max = ans[numsSize-1];
    free(ans);
    return max;
}
