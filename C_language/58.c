int lengthOfLastWord(char * s){
    int sum = 0, pos = strlen(s)-1;
    while(s[pos]==' ') pos--;
    for(int i=pos;i>-1;i--){
        if(s[i]==' '){
            break;
        }else{
            sum++;
        }
    }
    return sum;
}