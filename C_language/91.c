/*
 * 參考他人所得到的解答，使用的方式是找出規律，一層層的分析答案的總合。
 * 使用的方式是設定一個table，紀錄每個index的所有解答數量。
 * 如果s[0]為 0 代表無法解碼，不是則table[0] = 1 ， 一種解答。
 * 如果s[1]為，只要s[0]不是0，table[1]就是1。
 * 接著就能開始使用規律尋找答案了，當搜尋到index = 2時，我們就能夠依循前面兩個位置去判斷答案。
 * step1 : s[i-1] 是否為零(0)?，依此分成兩個方向
 * 第一類:
 * step2 : 如果s[i-1] = 0，代表我們還需要做三個判斷。
 * step3 : 如果s[i-2] = 1，或者s[i-2] = 2 ，代表只能單獨的解碼這個答案(10 or 20) => table[i] = table[i-1];
 * 第二類:
 * stpe2 : 如果s[i-1] !=0，一樣要做三個判斷。
 * step3 : 如果s[i-2] = 2 ， 由於可解碼的範圍在21~26，所以還要判斷0<s[i-2]<7，符合的話 => table[i] = table[i-1] + table[i-2] 。
 * 否則，就如同第一類的step3一樣，只能單獨解碼這個答案 table[i] = table[i-1];
 * step4 : 如果s[i-1] = 1 ， 因為範圍在11~19，所以必定可以得到 table[i] = table[i-1] + table[i-2];
 * syep5 : 如果既不是1，也不是2，代表他必定只能單獨解碼，那就會得到table[i] = table[i-1];
 */

int numDecodings(char * s){
    if(s[0]=='0') return 0;
    int i, length = strlen(s);
    int table[length+1];
    table[0] = 1;
    table[1] = 1;
    for(i=2;i<=length;i++){
        if(s[i-1]=='0'){
            if(s[i-2]=='1' || s[i-2]=='2'){
                table[i] = table[i-2];
            }else{
                return 0;
            }
        }else{
            if(s[i-2]=='1'){
                table[i] = table[i-1] + table[i-2];
            }else if(s[i-2]=='2' && (s[i-1] - '0')<7){
                table[i] = table[i-1] + table[i-2];
            }else{
                table[i] = table[i-1];
            }
        }
    }
    return table[length];
}



















// 失敗的版本 - 花太久時間
repeat(char * s, int pos, int* ans, int length){
    if(s[pos]=='\0'){
        (*ans)++;
        return;
    }
    if(s[pos]!='0'){
        int letter1 = s[pos] - '0';
        if(letter1>0 && letter1<27) repeat(s, pos+1, ans, length);
        if(letter1<3 && letter1>0){
            letter1 = letter1*10+(s[pos+1] - '0');
            if(letter1>0 && letter1<27) repeat(s, pos+2, ans, length);
        }
    }
}

int numDecodings(char * s){
    if(s[0]=='0') return 0;
    int ans = 0, length = strlen(s);
    repeat(s, 0, &ans, length);
    return ans;
}