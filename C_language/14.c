char * longestCommonPrefix(char ** strs, int strsSize){
    int pos = 0;
    int i,j,k;
    if(strsSize==1) return strs[0];
    for(i=0;i<strlen((char*)strs[0]);i++){
        for(j=1;j<strsSize;j++){
            if(strlen((char*)strs[j])>=i){
                if(strs[j][i]!=strs[0][i]){
                    strs[0][i] = '\0';
                    return strs[0];
                }
            }
        }
    }
    return strs[0];
}