/*
 * 以遍歷的方式搜尋答案，每個root節點都會根據其父節點和子節點去做範圍的變更。
 * 假設節點3其父節點為5(上界),1(下界)，節點往left搜尋，那麼其左節點的值應該變更上界為3,下界不變。
 * 往右則是改變下界為3,上界不變。
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool repeat(struct TreeNode* root, long max, long min){
    if(root!=NULL){
        if(max!=9223372036854775807 && max <= root->val) return false;
        if(min!=-9223372036854775808 && min >= root->val) return false;
        if(!repeat(root->left,root->val,min)) return false;
        if(!repeat(root->right,max,root->val)) return false;
    }
    return true;
}
bool isValidBST(struct TreeNode* root){
    return repeat(root,9223372036854775807,-9223372036854775808);
}