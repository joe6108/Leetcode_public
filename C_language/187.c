/*
 * 結果
 * Runtime : 152ms Beats 11.76%of users with C
 * Memory  : 126.47MB Beats 5.88%of users with C
 */
/*
 * 解題思路
 * 直接使用字典樹去找出答案。
 */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeLink{
    struct TreeLink* A[26];
    int count;
}TreeLink;

struct TreeLink* createNode(){
    TreeLink* new_node = malloc(sizeof(TreeLink));
    for(int i=0;i<26;i++) new_node->A[i] = NULL;
    new_node->count = 0;
    return new_node;
}

void free_all_TreeLink(TreeLink* root){
    if(!root) return;
    for(int i=0;i<26;i++){
        if(root->A[i]){
            free_all_TreeLink(root->A[i]);
        }
    }
    free(root);
}

void get_ans(TreeLink* root, int* total, char** ans, int level, char* table){
    if(level == 10){
        // printf("\n");
        // for(int i=0;i<10;i++){
        //     printf("%c", table[i]);
        // }
        // printf("\n");
        strncpy(ans[*total], table, 10);
        ans[*total][10] = '\0';
        (*total)++;
        return;
    }
    for(int i=0;i<26;i++){
        if(root->A[i] && root->A[i]->count>=1){
            //printf("i = %d level = %d\n", i, level);
            table[level] = i + 'A';
            get_ans(root->A[i], total, ans, level+1, table);
        }
    }
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    int len = strlen(s);
    TreeLink* root = createNode();
    int index = 0;
    TreeLink* head = NULL;
    for(int i=0;i<=(len-10);i++){
        head = root;
        for(int j=i;j<i+10;j++){
            index = s[j] - 'A';
            if(!head->A[index]){
                head->A[index] = createNode();
            }else{
                head->A[index]->count +=1;
            }
            head = head->A[index];
        }
    }
    head = root;
    char** ans = malloc(sizeof(char*)*2000);
    for(int i=0;i<2000;i++){
        ans[i] = malloc(sizeof(char)*11);
    }
    char table[11] = {0};
    int total = 0;
    get_ans(root, &total, ans, 0, table);
    *returnSize = total;
    // for(int i=0;i<total;i++){
    //     for(int j=0;j<10;j++){
    //         printf("%c", ans[i][j]);
    //     }
    //     printf("\n");
    // }
    free_all_TreeLink(root);
    return ans;
}