/*
 * 結果
 * Runtime : 12ms Beats 36.97%of users with C
 * Memory  : 5.80MB Beats 100%of users with C
 */
/*
 * 解題思路
 * 這題是參考網路上其他人的想法寫出來的，有人找出了這題的規律在於因為是連續的數字，所以觀察下來就會發現，從高bit
 * 數往下看時，只要發現最大(right)跟最小(left)的bit數不同，就會是Bitwise AND了。
 * 所以我就照著這個思路，從最高bit開始比較，利用EOR查看bit是否相同，不同的話，就立即跳出迴圈，並讓當前bit，
 * 以及之後bit都為0，然後再用2進位乘法就可以得出答案。
 */

int rangeBitwiseAnd(int left, int right) {
    if(left == 0 || right ==0) return 0;
    int ans[32] = {0};
    int temp = 0, total = 0, left_s = 0;
    for(int i=31;i>=0;i--){
        left_s = left>>i & 1;
        temp = (left_s^(right>>i)) & 1;
        //printf("temp = %d, left_s = %d\n", temp, left_s);
        if(temp == 1){
            break;
        }else{
            ans[i] = left_s;
        }
    }
    for(int i=31;i>=0;i--){
        total += ans[i]*pow(2,i);
    }
    return total;
}

