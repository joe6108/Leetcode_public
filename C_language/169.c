/*
 * 結果
 * Runtime : 8ms Beats 98.13%of users with C
 * Memory  : 8.47MB Beats 48.45%of users with C
 */
/*
 * 解題思路
 * 對於這題，我沒有想出符合題目要求的方法，所以我參考了網路上其他人的思路去解決
 * 網站來自: https://clay-atlas.com/blog/2022/02/21/leetcode-169-majority-element/
 * 我能想到的就符合這個網站的前兩個，也就是做排列，或是Hash-map直接解決。
 * 但排列會超出O(n)的處理順序，Hash-map則會造成大量記憶體的使用。
 * 所以最後是使用投票的方式，透過家+跟-去取得最後數量最多的一個答案，
 * 這是一個非常單純的解決方法，因為答案必定超過半數，這代表我可以透過遇到不同的數字，
 * 就做-1，一樣則+1，如果被扣到0，只要換成下一個去做+-即可。
 */

int majorityElement(int* nums, int numsSize) {
    int target = nums[0], count = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=target){
            count--;
        }else{
            count++;
        }
        if(count==0){
            target = nums[i];
            count = 1;
        }
    }
    return target;
}