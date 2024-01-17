/*
 * 結果
 * Runtime : 0ms Beats 100%of users with C
 * Memory  : 7.00MB Beats 51.60%of users with C
 */
/*
 * 解題思路
 * 題目的意思是要求出二元樹所有最右邊的數值，整理成一個數列回傳。
 * 在看到這題的當下，我想到的方法就是利用正常的遞迴去尋求答案，不過順序必須是先右再左，
 * 而我只要透過level這個變數去紀錄當下在第幾層，就能夠在每次找到當層最右的值時，將答案填入數列中。
 * 比較好理解的方式就是每次都會從左上至右下找值，這樣就能確保答案的正確性。
 * 不過知道答案的找法之後，就是答案的大小會跟這棵樹有幾層有關，但我只追求速度，所以我直接設定101當作
 * 大小，所以在記憶體上我做得不夠完美。
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
void reserve(struct TreeNode* root, int* returnSize, int level, int* ans){
    if(!root) return;
    if(ans[level] == 101){
        ans[level] = root->val;
        (*returnSize)+=1;
    }
    reserve(root->right, returnSize, level+1, ans);
    reserve(root->left, returnSize, level+1, ans);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(101*sizeof(int));
    for(int i=0;i<101;i++) ans[i] = 101;
    *returnSize = 0;
    reserve(root, returnSize, 0, ans);
    return ans;
}