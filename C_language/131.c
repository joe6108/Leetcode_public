/*
 * 這題是我第一次遇到的三維題目，經過了這題之後，我更加了解了多重指標的意義了，也讓我知道了寫這種程式會有的一種隨時都有bug的感覺。
 * 這題的解法很好理解，因為題目要求的是所有可能性，所以我第一個就想到了使用遍歷，搜尋所有的結果，不過僅使用遍歷的話，會發現實在是
 * 太慢了，畢竟從題目可以看出來，如果每次找到一個答案之後，再重頭開始找會太慢，所以我們需要使用DP(Dynamic program)動態規劃，簡單
 * 來說就是我先設置一個暫存空間(Table)，當找到一個答案之後，我可以透過遍歷的回朔，回到取得最後一部分之前的Table後，繼續尋找下一個
 * 部分答案，這方面可能就需要比較多使用遍歷的經驗才會理解，再來就可以從中得出答案了。
 */

/*
 * 結果: 
 * Runtime 364ms Beats 88.24%
 * Memory 84.04MB Beats 100%
 * 這題的執行速度從高到低的平均人數都是一致，非常誇張。
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isPalindrome(char* s, int l, int r){
    while(r > l){
        if(s[r] != s[l]){
            return false;
        }
        r--;
        l++;
    }
    return true;
}
// pos 當前位置 table 暫存空間，用來儲存每個分段的數量 table_pos 總共分成了幾段 ans 答案
void sort_Traver(char* s, int* returnSize, int** returnColumnSizes, int length, int pos, char* table, int table_pos, char*** ans){
    //printf("enter loop, pos = %d\n", pos);
    // 代表取到了最後的值了
    if(pos == length){
        // 空間分配
        ans[(*returnSize)] = malloc(sizeof(char*)*(table_pos)); 
        for(int i = 0 ; i < table_pos ; i++) ans[(*returnSize)][i] = malloc(sizeof(char) * (table[i] + 1));
        // 因為Table是儲存數量，不是實際的數值，所以需要用index去慢慢的遞增取值。
        int index = 0;
        for(int i = 0 ; i < table_pos ; i++){ 
            int range = table[i];
            for(int j = 0 ; j < range ; j++) ans[(*returnSize)][i][j] = s[index++];
            ans[(*returnSize)][i][range] = '\0';
        }
        // 設置回傳答案的最終結果。
        (*returnColumnSizes)[(*returnSize)] = table_pos; 
        (*returnSize) += 1;
        //printf("table_pos = %d, table[0] = %d, table[1] = %d\n", table_pos, table[0], table[1]);
        //printf("get a answer -- -- -- \n");
        return;
    }
    // 每次都是從起始值開始判斷是否為回文，透過回傳位置的方式找出回文。
    for(int i = pos ; i < length ; i++){ 
        if(isPalindrome(s, pos, i)){ // 如果回傳true，代表是回文
            //printf("isPalindrome - pos = %d, i = %d, table_pos = %d\n", pos, i, table_pos);
            table[table_pos] = i - pos + 1; // 總共有多少個字元是回文
            sort_Traver(s, returnSize, returnColumnSizes, length, i + 1, table, table_pos + 1, ans); 
        }
    }
    return;
}

char *** partition(char* s, int* returnSize, int** returnColumnSizes){
    int length = strlen(s); //length得出的長度不包含字尾'\0'
    if(length == 0) return 0;
    double space = pow(2, length); // 假設aaa為輸入，推斷出其所有值大概會等於2的3次方。
    // init
    char*** ans = malloc(sizeof(char**)*space);
    (*returnColumnSizes) = malloc(sizeof(int)*space);
    (*returnSize) = 0;

    /*
     * table is a temp space, as dp(dynamic program)，用來儲存每個分段的字元個數。
     */
    char* table = malloc(sizeof(char)*length);
    sort_Traver(s, returnSize, returnColumnSizes, length, 0, table, 0, ans); 
    //for(int i=0;i<(*returnSize);i++) printf("%d\n", table[i]);
    free(table);
    return ans;
}

/* 用來理解大概要如何分配空間及答案。
(*returnColumnSizes)[0] = 3;  
ans[0] = malloc(sizeof(char*)*4);
ans[0][0] = malloc(sizeof(char)*100);
ans[0][1] = malloc(sizeof(char)*100);
ans[0][2] = malloc(sizeof(char)*100);
ans[0][0][0] = 'a';
ans[0][0][1] = '\0';
ans[0][1][0] = 'a';
ans[0][1][1] = '\0';
ans[0][2][0] = 'b';
ans[0][2][1] = '\0';
(*returnColumnSizes)[1] = 2;
ans[1] = malloc(sizeof(char*)*2);
ans[1][0] = malloc(sizeof(char)*100);
ans[1][1] = malloc(sizeof(char)*100);
ans[1][0][0] = 'a';
ans[1][0][1] = 'a';
ans[1][0][2] = '\0';
ans[1][1][0] = 'b';
ans[1][1][1] = '\0';
*/