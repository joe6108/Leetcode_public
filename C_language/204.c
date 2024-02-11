/*
 * 結果
 * Runtime : 148ms Beats 66.99%of users with C
 * Memory  : 37.06MB Beats 29.61%of users with C
 */
/*
 * 解題思路
 * 原先是使用直接暴力的方式解決，但因為太慢，所以找了其他人的解決方法，解釋放入程式中
 */

int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    // 初始化一個布爾數組，表示每個數字是否為質數
    bool *isPrime = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false; // 0和1不是質數

    /*
     * 這裡使用 i * i < n 作為條件，是因為如果某個數i的平方大於n，那麼它的倍數就一定超過n，就不需要再檢查了。
     */
    // 使用埃拉托斯特尼篩法找到質數
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
            /*
             * 在外層循環中，首先檢查 isPrime[i] 是否為真。如果 isPrime[i] 為真，
             * 則表示i是質數，因此內層循環遍歷i的所有倍數（從i的平方開始，因為小於i的
             * 倍數已經在之前的迭代中被標記為非質數），並將它們標記為非質數，即 isPrime[j] = false。
             */
        }
    }

    // 計算質數的數量
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    // 釋放動態分配的內存
    free(isPrime);

    return count;
}