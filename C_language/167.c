/*
 * 結果
 * Runtime : 9ms Beats 66.36%of users with C
 * Memory  : 7.90MB Beats 24.67%of users with C
 */
/*
 * 解題思路
 * 簡單的透過兩邊做總和，依照其對target的對比去做向左或向右查詢。
 * 
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int l = 0, r = numbersSize - 1;
    int* ans = malloc(sizeof(int)*2);
    *returnSize = 0;
    while(l < r){
        int temp = numbers[l] + numbers[r];
        if(temp == target){
            ans[0] = l+1;
            ans[1] = r+1;
            *returnSize = 2;
            break;
        }else if(temp > target){
            r--;
        }else{
            l++;
        }
    }
    return ans;
}