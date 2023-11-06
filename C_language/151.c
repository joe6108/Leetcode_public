/*
 * 結果
 * Runtime : 0 ms Beats 100.00%of users with C
 * Memory  : 6.96MB Beats 65.96%of users with C
 */
/*
 * 解題思路
 * 
 */

/*
 * 兩階段處理，第一階段: 探討真正長度的s 第二階段: 將值倒過來傳入答案中
 */

// 已釋放記憶體
char* reverseWords(char* s) {
    int len = strlen(s), total = 0, count = 0;
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            if(s[i+1]==' ' || s[i+1]=='\0'){
                count++; //多少個字串
            }
            total++; //真實總長
        }
    }
    total+=count; // 真實實際上的總長(含空白跟'\0')
    char* ans = malloc(sizeof(char)*total);
    ans[total-1] = '\0';
    int section = 0; //每段字串的大小
    total-=2;
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            section++;
            if(s[i+1]==' ' || s[i+1]=='\0'){
                int temp = i;
                while(section>0){
                    ans[total--] = s[temp--];
                    section--;
                }
                if(total>0) ans[total--] = ' ';
            }
        }
    }
    int start = 0;
    while(ans[start]!='\0'){
        s[start] = ans[start];
        start++;
    }
    s[start] = '\0';
    free(ans);
    return s;
}

// 未釋放記憶體
char* reverseWords(char* s) {
    int len = strlen(s), total = 0, count = 0;
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            if(s[i+1]==' ' || s[i+1]=='\0'){
                count++; //多少個字串
            }
            total++; //真實總長
        }
    }
    total+=count; // 真實實際上的總長(含空白跟'\0')
    char* ans = malloc(sizeof(char)*total);
    ans[total-1] = '\0';
    int section = 0; //每段字串的大小
    total-=2;
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            section++;
            if(s[i+1]==' ' || s[i+1]=='\0'){
                int temp = i;
                while(section>0){
                    ans[total--] = s[temp--];
                    section--;
                }
                if(total>0) ans[total--] = ' ';
            }
        }
    }
    return ans;
}