//白癡題目 發現了很暴力簡單的解法
/*
 * 思路和上一題一樣，一開始我是從兩個面向去思考，一個是每次都要賺單筆最大值，一個是有得賺就要賺，而實際做了之後，我發現了兩個都要達成，也就是一旦發現
 * 沒辦法繼續賺的時候，就先賣出，並且買入更新一筆的股，持續到結束。
 */
//白癡題目
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==1) return 0;
    int max = 0, min = prices[0], sum = 0;
    for(int i=1;i<pricesSize;i++){
        int temp = prices[i] - min; // 先判斷是否有獲利。
        if(temp > max){ //有獲利或有持續獲利時的判斷。
            max = temp;
        }else{ // 代表發現有更低的股價，可以換股了。
            sum+=max;
            min = prices[i];
            max = 0;
        }
    }
    if(max!=0) sum+=max; 
    return sum;
}