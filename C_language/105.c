/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
 *  preorder = [1,2,4,8,9,5,11,3,6,12,13,7,10,15,14]
 *  inorder  = [8,4,9,2,5,11,1,13,12,6,3,7,15,10,14]
 *  output = 
 *  [1,2,3,4,5,6,7,8,9,null,11,12,null,null,10,null,null,null,null,null,null,13,null,15,14]
 */

struct TreeNode* repeat(int* preorder, int pre_start, int pre_end, int* inorder, int in_start, int in_end){
    //printf("pre_start = %d, pre_end = %d, in_start = %d, in_end = %d\n", pre_start, pre_end, in_start, in_end);
    if(in_start >= in_end || pre_start>=pre_end){
        //printf("return null\n");
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[pre_start];
    int i = 0;
    for(i=in_start;i<in_end;i++){
        if(inorder[i]==preorder[pre_start]) break;
    }    
    //printf("preorder[pre_start] = %d, i=%d\n", preorder[pre_start], i);
    root->left = repeat(preorder, pre_start+1, pre_start+i-in_start+1, inorder, in_start, i);
    root->right = repeat(preorder, pre_start+i-in_start+1, pre_end, inorder, i+1, in_end);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return repeat(preorder, 0, preorderSize, inorder, 0, inorderSize);
}