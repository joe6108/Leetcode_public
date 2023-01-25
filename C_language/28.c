int strStr(char * haystack, char * needle){
    int pos = 0, key = 1,i,j;
    while(haystack[pos]!='\0'){
        if(haystack[pos]==needle[0]){
            i = pos;
            j = 0;
            while(needle[j]!='\0'){
                if(haystack[i]!=needle[j]){
                    key = 0;
                    break;
                }
                j++;
                i++;
            }
            if(key == 1){
                return pos;
            }else{
                key = 1;
            }
        }
        pos++;
    }
    return -1;
}