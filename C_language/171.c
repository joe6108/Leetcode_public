/*
 * 結果
 * Runtime : 0 ms Beats 100% of users with C
 * Memory  : 6.5 MB Beats 34.75%of users with C
 */
/*
 * 解題思路
 * 按照bit換算即可。
 */


int titleToNumber(char* columnTitle) {
    long long total = 0, bit_n = 1;
    int len = strlen(columnTitle);
    for(int i=(len-1);i>=0;i--){
        total += bit_n * (columnTitle[i] - 'A' + 1);
        bit_n*=26;
    }
    return total;
}