/*
 * 結果
 * Runtime : 0ms Beats 100%of users with C
 * Memory  : 5.42MB Beats 100%of users with C
 */
/*
 * 解題思路
 * 以有無進入2位數為界，只要總和回到個位數，就可以透過是否為7或1判斷是否快樂，其餘都為no happy。
 */

bool isHappy(int n) {
    int buffer[12] = {0};
    int index = 0, sum = 0;
    while(n>9){
        sum = 0;
        index = 0;
        while(n>0){
            buffer[index++] = n % 10;
            n/=10;
        }
        for(int i=0;i<index;i++){
            sum+=pow(buffer[i], 2);
        }
        n = sum;
    }
    if(n == 1 || n == 7){
        return true;
    }
    return false;
}