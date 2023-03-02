/*
 * 1.我的想法是，每當遇到 '/' 的時候開始判斷，如果遇到 '/' 每次都只尋找最後一個 '/' 開始判斷，例如: ////////abc -> 從 index0開始，直接
 *  一直地跳過，直到找到最後的 '/' -> '/abc' 
 * 2.再來，如果解決了重複斜線的問題，再來就是路徑了，每當'/'之後遇到了 '.' 就進入判斷式，做兩種判斷
 * 判斷一 : 如果遇到  /./ 或是 /.'\0' (這邊的\0為結束，例如: "/a/." 這種)，就跳過。
 * 判斷二 : 如果遇到  /../ 或是 /..'\0'(例如: /a/b/..) ， 就先判斷他能不能回到上個路徑(pos>0?)，如果可以，則尋找上個路徑的位置，從上個路徑
 * 開始寫入新路徑。
 * 3. 旗魚就是單純地將各個字元寫入答案則可。
 */



char * simplifyPath(char * path){
    int len = strlen(path), pos = 0, i;
    char *ans = malloc(sizeof(char)*(len+1));
    for(i=0;i<len;i++){
        while(path[i]=='/' && path[i+1]=='/') i++;
        if(path[i]=='/'){
            if(pos!=0 && i+1==len) continue;
            if(path[i+1]=='.'){
                if(path[i+2]=='/' || path[i+2]=='\0'){
                    i++;
                    continue;
                }else if(path[i+2]=='.'){
                    if(path[i+3]=='/' || path[i+3]=='\0'){// /a/..   /a
                        i+=2;
                        if(pos>0){
                            pos--;
                            while(pos>0 && ans[pos]!='/') pos--;
                        }
                        continue;
                    }
                }
            }
            
        }
        ans[pos++] = path[i];
    }
    if(pos==0) ans[pos++] = '/';
    ans[pos] = '\0';
    return ans;
}