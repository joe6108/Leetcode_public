char * longestPalindrome(char * s){
    int max = 1; 
    int max_pos = 0; 
    int pos = 1; 
    int right = 0;
    int left = 0;
    int count = 1;
    int length = strlen(s) + 1;

    if(s[0]=='\0') return 0;
    char* tmp = (char*)calloc(length,sizeof(char));
    if(!tmp){
        return 0;
    }
    while(s[pos]!='\0'){
        if(s[right]==s[pos]){
            right++;
            count++;
            if(count > max){
                max = count;
                max_pos = left;
            }
        }else{
            while(((left-1)!=-1) && ((right+1)<length)){
                if(s[right+1] == s[left-1]){
                    right++;
                    left--;
                    count+=2;
                }else{
                    break;
                }
            }
            if(count > max){
                max = count;
                max_pos = left;
            }
            right = pos;
            left = right;
            count = 1;
        }
        pos++;
    }
    for(int i=max_pos, j=0;i<(max_pos+max);i++, j++){
        tmp[j] = s[i];
    }
   
   
   return tmp;
}