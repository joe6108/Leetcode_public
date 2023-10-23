/*
 * 結果
 * Runtime : 9 ms Beats 35.38%of users with C
 * Memory  : 7.50MB Beats 42.31%of users with C
 */

/*
 * 這題的思路是利用位元運算的概念實現的，建議先理解上一題的做法。
 * 用例子比較好說明，假設是2, 2, 3, 2來說，我們只要將其轉為位元數>
 * 1 0 
 * 1 0
 * 1 0
 * 1 1 
 * ------相加
 * 4 1 
 * 就會注意到 4 % 3 = 1 跟 1 % 3 = 1 分別為 3 的位元數，也就是出現三次的數字的位元會被3整除，剩下的餘
 * 數就會是3的位元數，也就是答案。
 * 所以解法就是統整每個位元的數量，然後分別除3之後，再利用位元運算的方法相加，就可以得出解答了。
 * 
 */


int singleNumber(int* nums, int numsSize){
    long long ans[32] = {0};
    // 00010101
    for(int i = 0 ; i < numsSize ; i++){
        for(int j=0;j<32;j++){
            ans[j] += (nums[i] >> j) & 1;
        }
    }
    int result = 0;
    for(int i=0;i<32;i++){
        result += (ans[i] % 3) << i;
    }
    return result;
}