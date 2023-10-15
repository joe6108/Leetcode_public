/*
 * 這題就沒什麼意思，只要照題目的題意運行就好，也就是先將大寫轉小寫，然後再確認當下index是否為有效值，然後再做判斷即可，但我是反過來，先判斷有效值
 * 再判斷是否為大寫，但我只是題目沒看完，所以就反過來做了，另外該注意的是長度為1時，就連空白鍵也能當回文，主要是題目認為其為無效值，所以就得當作是
 * 空字串來看，也就會變成有效的回文了。
 */

bool accept_char(char s){ //判斷是否為有效值
    return (( (int)s > 64 && (int)s < 91) || ((int)s > 96 && (int)s < 123) || ((int)s > 47 && (int)s < 58) ) ? true : false;
}

bool isUpper(char s){ //判斷是否為大寫
    return ((int)s > 64 && (int)s < 91) ? true : false;
}

bool isPalindrome(char * s){
    int length = strlen(s);
    if(length==1) return 1;
    //printf("%c", s[0]+32);
    int l = 0, r = length - 1;
    while(r > l){
        while(r > l && !accept_char(s[r])) r--;
        while(r > l && !accept_char(s[l])) l++;
        if(isUpper(s[l])) s[l]+=32;
        if(isUpper(s[r])) s[r]+=32;
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            return false;
        }
    }
    return true;
}