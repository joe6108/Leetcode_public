/*
 * 結果
 * Runtime : 11ms Beats 6.67%of users with C
 * Memory  : 8.10MB Beats 13.33%of users with C
 */
/*
 * 解題思路
 * 透過實現實際在進行除法時會有的過程去做解答。
 * 分為兩階段執行。
 * 第一階段: 算出整數位的數值。
 * 第二階段: 紀錄每一段除數的狀態，將其存入table中，找出會發生重複的地方。
 * 其他比較需要注意的就是正負數的處理以及數值的範圍要改變。
 * 例如INT是不夠我們做使用的，所以我們使用long long。
 * 正負數的問題，我們只透過正數做計算，所以會將正負放入一個變數做判斷。
 * 剩下的就是一些移位的問題了，像是重複的小數要加入()，或是正負數需要去做移位。
 * 
 */


char* fractionToDecimal(int numerator, int denominator) {
    int positive = 1;
    if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
        positive = -1;
    }
    long long a1 = numerator, b1 = denominator, one_stage = 0;
    if(a1<0) a1*=(-1);  
    if(b1<0) b1*=(-1);
    if(a1 > b1){
        one_stage = a1/b1;
        a1%=b1;
    }
    char* ans = malloc(sizeof(char)*10000);
    int index = 0;
    char temp = '0';
    if(one_stage==0){
        ans[index++] = '0';
    }else{
        while(one_stage != 0){
            //printf("%lld\n", one_stage);
            ans[index++] = (one_stage % 10) + '0';
            one_stage/=10;
        }
        int l = 0, r = index-1;
        while(r > l){
            temp = ans[l];
            ans[l] = ans[r];
            ans[r] = temp;
            r--;
            l++;
        }
    }
    //判斷是否有.
    if(a1!=0){
        ans[index++] = '.';
        char table[1000][1000] = {0};
        int table_count = 0, table_temp = 0, table_index = 0, repeat_index = index;
        bool repeat = false;

        int x = 0, a1_len = 0, a2_len = 0, i = 0, temp_index = 0;
        while(a1 != 0){
            a1 *= 10;
            table_index = 0;
            // 暫存數值
            table_temp = a1;
            // 將可能重複的結果放入table
            a1_len = 0;
            while(table_temp != 0){
                table[table_count][table_index++] = (table_temp % 10) + '0';
                table_temp/=10;
                a1_len++;
            }

            table[table_count][table_index] = '\0';
            table_count++;
            // 判斷這是否為重複的被除數
            for(i=0;i<(table_count-1);i++){
                table_index = 0;
                a2_len = strlen(table[i]);
                if(a1_len == a2_len){
                    while(table[i][table_index] != '\0'){
                        if(table[i][table_index] != table[table_count-1][table_index]){
                            break;
                        }
                        table_index++;
                    }
                    if(table_index==a2_len){
                        repeat = true;
                        repeat_index = repeat_index + i;
                        break;
                    }   
                }
            }
            if(repeat){
                ans[index++] = ')';
                temp_index = index++;
                while(temp_index > repeat_index){
                    ans[temp_index] = ans[temp_index-1];
                    temp_index--;
                }
                ans[repeat_index] = '(';
                break;
            } 
            // 開始做除法
            ans[index++] = (a1 / b1) + '0';
            a1%=b1;
        }
    }
    ans[index++] = '\0';
    if(positive!=1){
        while(index > 0){
            ans[index] = ans[index-1];
            index--;
        }
        ans[0] = '-';
    }
    return ans;
}