/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
# define NULL 0

struct TreeNode {
    int val;
    struct TreeNode *left;
     struct TreeNode *right;
};
void sumTraver(struct TreeNode* root, int* ans, int sum){
    if(root == NULL) return;
    sum = 10*sum + root->val; // 計算至目前為止的值。
    if(root->left == NULL && root->right == NULL) (*ans) += sum; //最終值。
    sumTraver(root->left, ans, sum); 
    sumTraver(root->right, ans, sum);
}

int sumNumbers(struct TreeNode* root){
    int ans = 0;
    sumTraver(root, &ans, 0);
    return ans;
}