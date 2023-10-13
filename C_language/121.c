/*
 * 這題的方法就是以暴力破解的方式處理，因為每次都要求得最大獲利的數字，所以我使用的方法是每次都找出最低買進的價格，接著發現能獲利，就更新看看最大值，
 * 如果發現有更低的價格，就更新買進的最低價格的值，這個方法我一開始是覺得有漏洞的，或許會因為更新最低買進的值，就會忽略一些差值，可是當我仔細想過之後
 * 我發現如果你原本的價格雖然夠低，但只要發現更低之後，遇到更高的還是會得到更多的獲利，所以才比較想通這題。
 *
 */

int maxProfit(int* prices, int pricesSize){
    if(pricesSize==1) return 0;
    int min = prices[0];
    int max = 0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i] < min){
            min = prices[i];
            continue;
        }
        int temp = prices[i] - min;
        if(temp > max) max = temp;
    }
    return max;
}