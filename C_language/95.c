/*
 * 這題的解法我覺得有點複雜，畢竟是種資料結構，簡單來說就是讓1~n的值，輪流當作root的根部，再去尋找剩餘的答案。
 * 然後我們將會利用DFS深度優先搜尋演算法來處理，也就是從最底部開始倒過來建立我們的樹，假設n=3，步驟如下:
 * 第一步: 先輪流從1~N取值，假設我們按照步驟來，第一個先找到1。
 * 第二步: 接著我們會繼續往下找，往1的左邊和右邊，分別持續找下個值，而這時就要遵守root=1，那麼左邊必小於1，右邊必大於1。
 * 也就是左邊會從1~1-1(0)開始找，右邊會從2~3開始找。
 * 第三步: 在找左邊的時候，會很明顯的發現沒有任何值可以接，那我們就可以找到1的左半部只會是null
 * 第四步: 而右邊，就可以分別從2~3當作下一個root，繼續從左邊和右邊繼續找root，輪流這樣。
 * 最後一步: 我們可以看出1的左半邊只能是null，那右邊則是，一直找，直到找到沒有，也就是先建立3，再來2，最後回到1這樣，最後就可以交出答案了。
 *
 */





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Tree_count(int n){
    if(n<=1) return 1;
    int count = 0;
    for(int i=1;i<=n;i++){
        int left = Tree_count(i-1);
        int right = Tree_count(n-i);
        count += left * right;
    }
    return count;
}

struct TreeNode** repeat(int start, int end, int* returnSize, struct TreeNode** ans){
    if(start>end){
        ans[*returnSize] = NULL;
        (*returnSize)++;
        return;
    }
    for(int i=start;i<=end;i++){
        //create a node
        struct TreeNode* root = malloc(sizeof(struct TreeNode));
        root->val = i;
        root->left = NULL;
        root->right = NULL;
        struct TreeNode** left_node = malloc(sizeof(struct TreeNode*)*Tree_count(i-1));
        struct TreeNode** right_node = malloc(sizeof(struct TreeNode*)*Tree_count(end-i));
        int left_Size = 0, right_Size = 0;
        repeat(start,i-1,&left_Size,left_node);
        repeat(i+1,end,&right_Size,right_node);
        for(int j=0;j<left_Size;j++){
            for(int k=0;k<right_Size;k++){
                root->left = left_node[j];
                root->right = right_node[k];
                ans[*returnSize] = malloc(sizeof(struct TreeNode));
                memcpy(ans[*returnSize],root,sizeof(struct TreeNode));
                (*returnSize)++;
            }
        }
    }
}

struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode** ans = malloc(sizeof(struct TreeNode*)*Tree_count(n));
    *returnSize = 0;
    repeat(1,n,returnSize,ans);
    return ans;
}