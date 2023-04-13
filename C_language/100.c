/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * 逐個檢查是否相等。
 *
 * 
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p!=NULL && q!=NULL){
        if(p->val==q->val){
            if(!isSameTree(p->left,q->left)) return false;
            if(!isSameTree(p->right,q->right)) return false;
        }else{
            return false;
        }
    }else if(p==NULL && q==NULL){
        return true;
    }else{
        return false;
    }
    return true;
}