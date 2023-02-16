













int lengthOfLongestSubstring(char * s){
    int max_count = 1; //
    int pos = 0; //
    int count = 1; //
    // ASCII碼中 小寫英文在97->122之間 ， 大寫則65->90之間
    int i = 1;
    if(!s[pos]) return 0;
    
    while(s[i]!='\0'){
        for(int j=pos; j<(count+pos);j++){
            if(s[j] == s[i]){
                if(count > max_count) max_count = count;
                pos = j+1;
                count = i-pos;
                break;
            }    
        }
        count++;
        i++;
    }
    if(count > max_count) max_count = count;
    return max_count;
}