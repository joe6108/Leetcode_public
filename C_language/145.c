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
void pre_traver(struct TreeNode* root, int* ans, int* total){
    if(!root) return;
    pre_traver(root->left, ans, total);
    pre_traver(root->right, ans, total);
    ans[(*total)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans = malloc(sizeof(int)*101);
    int total = 0;
    pre_traver(root, ans, &total);
    *returnSize = total;
    return ans;
}