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
void inorder_search(struct TreeNode* root, int* returnSize, int* ans){
    if(root==NULL) return;
    inorder_search(root->left, returnSize, ans);
    ans[*returnSize] = root->val;
    (*returnSize)++;
    inorder_search(root->right, returnSize, ans); 
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int range = 100;
    int* ans = malloc(sizeof(int)*range);
    *returnSize = 0;
    inorder_search(root, returnSize, ans);
    return ans;
}