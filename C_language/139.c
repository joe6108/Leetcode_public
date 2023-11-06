/*
void traver(char* s, char** wordDict, int wordDictSize, int s_len, bool* ans, char* s_table){
    int a = 0;
    while(s_table[a]!='\0'){
        printf("%c", s_table[a++]);
    }
    printf("\n");
    printf("ans = %d\n", *ans);
    if((*ans) == true){
        return;
    }
    for(int i=0 ; i<wordDictSize ; i++){
        int j = 0;
        while(s_table[j]!='\0'){
            if(wordDict[i][0] == s_table[j]){
                printf("enter j = %d\n", j);
                int s_init = j;
                int word_init = 0;
                while(wordDict[i][word_init]!='\0' && s_table[s_init]!='\0'){
                    if(wordDict[i][word_init] != s_table[s_init]) break;
                    word_init++;
                    s_init++;
                }
                if(wordDict[i][word_init]=='\0'){ //ccbb c__b
                    if(j==0 && s_table[s_init]=='\0'){
                        *ans = true;
                        return;
                    }
                    printf("yes\n");
                    char* new_table = calloc((s_len+1), sizeof(char));
                    int index = 0;
                    for(int k=0;k<s_len;k++){
                        if(k<j || k>(s_init-1)){
                            new_table[index++] = s_table[k];
                        }
                    }
                    new_table[index] = '\0';
                    traver(s, wordDict, wordDictSize, s_len, ans, new_table);
                    free(new_table);
                }
            }
            j++;
        }
    }
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int s_len = strlen(s);
    char* s_table = calloc((s_len+1), sizeof(char));
    strncpy(s_table, s, (s_len+1));
    bool ans = false;
    traver(s, wordDict, wordDictSize, s_len, &ans, s_table);
    free(s_table);
    return ans;
}

*/




/* 失敗的解法 
* 太久
 void traver(char* s, char** wordDict, int wordDictSize, int pos, int s_len, bool* ans){
    //printf("pos = %d, s_len = %d\n", pos, s_len);
    if((*ans) == true) return;
    for(int i=0 ; i<wordDictSize ; i++){
        int s_init = pos;
        int word_init = 0;
        if(wordDict[i][0] == s[s_init]){
            while(wordDict[i][word_init]!='\0' && s[s_init]!='\0'){
                if(wordDict[i][word_init] != s[s_init]) break;
                s_init++;
                word_init++;
            }
            //printf("i = %d, s_init = %d, word_init = %d\n", i, s_init, word_init);
            if(wordDict[i][word_init]=='\0'){
                if(s_init == s_len){
                    *ans = true;
                    break;
                }else{
                    traver(s, wordDict, wordDictSize, s_init, s_len, ans);
                }
            }
        }
    }
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int s_len = strlen(s);
    bool ans = false;
    traver(s, wordDict, wordDictSize, 0, s_len, &ans);
    return ans;
}
 *
 */