/*
 * 我的作法是限縮解決的方式，如果直接讓兩數相加做進位處理的話，就得考慮到進位時的長度限制，但如果事先給予最長的大小，又不確定是否會因為長度
 * 限制而做進位，那不如一樣給予最長的大小，然後將兩者相加的答案反向放置，最後再將結果倒過來就能解決了。
 * 那麼要思考的部分有兩點，第一是該給予的答案長度，第二是進位時的處理。
 * 首先解決第一點，由於他是二進位的相加，所以我們可以得知其最大長度只會是兩數長度的相加再加一(字串a的長度 + 字串b的長度 + 1)，
 * 這個加1是為了結束字串的 '\0' 所增加的。
 * 再來是第二個問題，進位要如何處理，只要先做完相加，再判斷大小是否大於1(也就是2或3)，就能夠進位，然後直接將進位放入下個位置即可。
 */
char * addBinary(char * a, char * b){
    int pos = 0, a_len = strlen(a)-1, b_len = strlen(b)-1;
    char *ans = malloc(sizeof(char)*(a_len+b_len+3));
    memset(ans,'0', sizeof(char)*(a_len+b_len+2));
    while(-1 < a_len || -1 < b_len || ans[pos]=='1'){
        if(-1 < a_len && -1 < b_len){
            ans[pos] = ((ans[pos] - '0') + (a[a_len--] - '0') + (b[b_len--] - '0') + '0');
        }else if(-1 < a_len){
            ans[pos] = ((ans[pos] - '0') + (a[a_len--] - '0') + '0');
        }else if(-1 < b_len){
            ans[pos] = ((ans[pos] - '0') + (b[b_len--] - '0') + '0');
        }
        if((ans[pos] - '0') > 1){
            ans[pos] = ((ans[pos] - '0')%2 + '0');
            ans[pos+1] = '1';
        }
        pos++;
    }
    ans[pos] = '\0';
    //for(int i=0;i<pos;i++) printf("%c ", ans[i]);
    char temp;
    for(int i=0;i<pos/2;i++){
        temp = ans[i];
        ans[i] = ans[pos-i-1];
        ans[pos-i-1] = temp;
    }
    return ans;
    
}