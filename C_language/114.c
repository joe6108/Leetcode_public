/*
 * 這題是要我們將二元數壓平為一條線，我一開始以為是變成single link的方式，結果不是，他是要變成二元樹的單一link。
 * 這題其實是想要我們透過省空間的方式去達成目的，但我想不到方法，於是就以最快的方式，直接建立一個陣列，
 * 透過儲存遍歷中的每個結果，照順序去一個個串聯完成題目。
 * 也就是說我這題完成的並不完全，之後會透過參考他人程式碼去學習。
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traver(struct TreeNode* root, struct TreeNode** temp, int* range){
    if(root==NULL) return;
    temp[(*range)++] = root;
    //printf("temp[range(%d)] = %d\n", (*range), root->val);
    traver(root->left, temp, range);
    traver(root->right, temp, range);
}

void flatten(struct TreeNode* root){
    if(!root) return;
    struct TreeNode** temp = malloc(sizeof(struct TreeNode*)*2001);
    if(!temp){
        printf("memory allocation failed");
        return;
    }
    int range = 0;
    traver(root, temp, &range);
    for(int i=0;i<(range-1);i++){
        temp[i]->left = NULL;
        temp[i]->right = temp[i+1];
    }
    temp[range-1]->left = NULL;
    temp[range-1]->right = NULL;
}