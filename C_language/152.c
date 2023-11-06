/*
 * 結果
 * Runtime : 3 ms Beats 96.13%of users with C
 * Memory  : 7.2 MB Beats 37.57%of users with C
 */
/*
 * 參照https://anj910.medium.com/leetcode-152-maximum-product-subarray-%E4%B8%AD%E6%96%87-38bc1e224017所想出來的
 * 解題思路
 * 為了將時間限縮在O(n)內，所以我們透過兩個變數max, min去尋找最大以及最小的解，因為在連續的數組中，我們會遇到
 * 負負的正的狀況發生，所以我們需要去尋找min這個最小解，找出隨時會突然出現的最大值。
 * 所以這題主要分為三個部份去執行。
 * 初始化是以max和min和ans都為num[0]，因為輸入至少會有一個值。
 * 第一部分: 在每次的for迴圈過程中，我們都需要將max跟min和下一個值相乘。
 * 第二部分: 如果相乘的成果符合max跟min的定義，那就沒問題，但如果不符合的話，我們就要有所更動，
 * 像是min原本是5，但下一個是6，乘完變成30無非也是變大，所以min要變成6(因為是連續)，從6開始繼續
 * 找最小值，相對的max也是一樣，假如原本是-1，遇到6，那就要換成6。
 * 第三部分: 但只到第二部分的話，我們會發現或許min原本是-1，但遇到-6，會突然變大的情況發生，相對的
 * max也是。
 * 所以我們就要在中間加入交換的部分，讓max跟min可以隨時交換，確保找出所有的局部連續相乘最大最小值。
 */

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maxProduct(int* nums, int numsSize) {
    int max = nums[0], min = nums[0], ans = nums[0], temp = 0;
    for(int i=1;i<numsSize;i++){
        min*=nums[i];
        max*=nums[i];
        if(max < min){
            swap(&max, &min);
        }
        if(min > nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
        
        if(max > ans) ans = max;
    }
    return ans;
}

// 失敗的解法，所需時間太久，因為是暴力破解

int maxProduct(int* nums, int numsSize) {
    int max = nums[0], mult = nums[0], end = 0;
    for(int i=1;i<numsSize;i++){
        mult = nums[i];
        end = i-1;
        while(end>=0){
            if(nums[end]==0) break;
            mult*=nums[end--];
            if(mult > max) max = mult;
        }
        if(nums[i] > max) max = nums[i];
    }
    return max;
}