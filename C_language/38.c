/*
The following is a problem where understanding is more important than implementation, the problem states that given an n, we must find the answer after n iterations, meaning if n=4, the following scenario occurs:
n=1: the starting point of all answers, considered as "1";
n=2: At this point, 2 must first read the answer of n=1, which is "1", this reading method is as follows: one 1, representing that at n=2, it considers n=1 as "11" (adding a quantity before the original number).
n=3: At this point, the reading is n=2 => "11", as it is continuous and repeated, the reading method is as follows: two 1, representing that it is considered as "21".
n=4: This is similar to n=3, but I think one more n=5 is needed to make it clearer. 1211.
n=5: The understanding at this time is "111221", this problem is not about finding the number of occurrences, but about reading the previous perception. When encountering 1211, it will first read until 2 as one 1, then encounter one 2, and finally encounter continuous and repeated 1, two 1. Finally, it is integrated into "11" + "12" + "21", and the final answer is 111221.
The above is the idea of this problem and can be solved according to the idea.
-- English translation by charGPT --

這是一題理解遠比實作重要的題目，題目的意思是給定一個n，我們必須找到跌代n次的答案，也就是說假設n=4，會有以下狀況發生。
n = 1 : 所有答案的起點，認作 "1" ;
n = 2 : 這時候2必須先去閱讀 n = 1時的答案，也就是"1"，這個閱讀方式為: 一個1(one 1)，代表 n = 2時，他將這個 n = 1認作為 "11"，(在原本的數字前加上一個數量)。
n = 3 : 這時候閱讀的為 n = 2 => "11" 因為他連續，且重複，所以她的閱讀方式為: 兩個1(two 1)，代表他認作為 "21" 。
n = 4 : 這個就像 n = 3 一樣，但對於這題我覺得要多一個 n = 5才可以，才會解釋得更加清楚。 1211
n = 5 : 這時的理解為 "111221" ， 這題並不是要求出出現過的數量，而是閱讀上一個的認知，遇到1211，會先閱讀完至2，當成一個1(one 1)，再遇到
一個2(one 2)，最後遇到連續，且重複的1，兩個1(two 1) ， 然後最後在統合成 "11" + "12" + "21"，最後的答案為: 111221。
以上就是這題的思路，並且按照思路解決即可。
*/



char tmp[10000];
void lookup(int n){
    if(n!=1){
        lookup(n-1);
    }else{
        tmp[0]='1';
        tmp[1]='\0';
        return;
    }
    int count = 0;
    char table[10000] = {0};
    int i,pos=0;
    for(i=0;i<strlen(tmp);i++){
        count++;
        if(tmp[i]!=tmp[i+1]){
            table[pos++] = count+'0';
            table[pos++] = tmp[i];
            count = 0;
        }
    }
    table[pos++] = '\0';
    strcpy(tmp, table);
}

char * countAndSay(int n){
    memset(tmp, 0, sizeof(tmp));
    lookup(n);
    return tmp;
}