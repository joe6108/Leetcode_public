/*
 * 利用單純的以中間值為準，分為左子樹以及右子樹，一直確立新的點，保持高度平衡的結果。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTreeHelper(int init_pos, int* nums, int last_pos){
    int index = (init_pos + last_pos)/2;
    //printf("init_pos = %d, last_pos = %d index = %d\n", init_pos, last_pos, index);
    if(init_pos > last_pos) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[index];
    root->left = buildTreeHelper(init_pos, nums, index-1);
    root->right = buildTreeHelper(index+1, nums, last_pos);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return buildTreeHelper(0, nums, numsSize-1);
}