/*
 * Runtime Beats 100%, Memory Beats 31.10%
 * 這個程式碼使用的是上一題的程式邏輯，但比較不同的是，這題要求我們不消耗任何額外的記憶體，所以我們就只將記憶體限制在答案的最大值上。
 * 於是乎這就讓這題和上一題有了巨大的差別，雖然可以透過一樣的方法，但就要多了一些小訣竅去處理。
 * 在過程中，我們可以知道這題是透過上一層去得去下一層的解答。
 * 而我們可以從中得出，每次只要將當前的值，加上前一個數值，就是下個答案的值。
 * example 1,2,1 下一層 1, 2(當下的值)+1(前一個值), 1(當下的值)+2(前一個值), 1，但如果我們透過當前陣列直接將值更新了。
 * 將會變成， 1 , 2(當下)+1(前個), 1(當下)+3(前個) , 1 ，(最前和最後固定會為1)。
 * 所以我們就需要兩個變數幫助我們處理這個問題，透過預先存取的方法去避免相加錯誤的情況發生。
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = (rowIndex+1);
    int* ans = malloc(sizeof(int)*(*returnSize));
    int temp, temp2; 
    ans[0] = 1;
    for(int i=1;i<=rowIndex;i++){
        temp2 = ans[0]; //初始化第一個值。
        for(int j=1;j<i;j++){
            temp = ans[j]; //此值會成為下一輪的基值，需要先儲存起來。
            ans[j] = ans[j] + temp2; //雖然更新了新值，但舊值仍會需要用到，所以預先使用temp儲存起來。
            temp2 = temp; //賦予下一輪去使用。
        }
        ans[i] = 1;
    }
    return ans;
}