/*
 * 結果
 * Runtime : 0 ms Beats 100%of users with C
 * Memory  : 6.1 MB Beats 89.8%of users with C
 */
/*
 * 解題思路
 * 主要就是將10進位轉換成26進位而已，可以用除法解決，但我沒想到所以用了比較自創的方式。
 * 先透過由低到高的每個bit去判斷範圍。
 * 判斷完成之後，就由bit最高的bit去對columnNumber去做減，先判斷bit的乘階，再判斷A~Z，
 * 但有可能會因為高bit的值會剛好等於columnNumber這個結果，導致低bit數會沒有值，變得
 * 不符合答案，所以需要-1去做bit控制。
 * 完成之後就可以了。
 * 
 * 
 */

char* convertToTitle(int columnNumber) {
    long long num = 26, count = 0, temp = 0, col_num = columnNumber;
    int ans_index = 0;
    char* ans = calloc(100, sizeof(char));
    temp = col_num;
    while(0 < temp - num){
        temp -= num;
        num *= 26;
        count+=1;
    }
    ans_index = count;
    for(int i=count;i>=0;i--){
        num = 1;
        temp = 1;
        for(int j=0;j<i;j++) num*=26;
        if(col_num - num * temp < 0){
            ans[i+1]-=1;
            col_num += num*26;
        }
        if(i>0 && num==col_num){
            num/=26;   
        }else{
            while(temp < 26 && (temp+1)*num <= col_num){
                temp++;
            }   
            if(i>0 && temp*num == col_num){
                temp--;
            }
        }
        col_num = col_num - num * temp;
        ans[i] = temp + 64;
    }
    ans[ans_index+1] = '\0';
    int l=0, r=ans_index;
    char a = '0';
    while(r>l){
        a = ans[r];
        ans[r] = ans[l];
        ans[l] = a;
        r--;
        l++;
    }
    return ans;
}