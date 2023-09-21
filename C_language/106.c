/*
    此方法是學習最快的解答而學會的。
    利用postorder擁有的特性，可以發現他最後面的值代表了root的頭，接著只要找到這個值，就可以套用在inorder中，找出其值的左節點及右節點
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize==0 || postorderSize==0) return NULL;
    int target = postorder[postorderSize-1];
    int i = 0;
    while(inorder[i]!=target) i++;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(&inorder[i+1], inorderSize-i-1, &postorder[i], postorderSize-i-1);
    return root;
}