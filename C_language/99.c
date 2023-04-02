/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void repeat(struct TreeNode* root, struct TreeNode** temp, struct TreeNode** first, struct TreeNode** second){
    if(root!=NULL){
        repeat(root->left,temp,first,second);
        if(*temp!=NULL){
            if((*temp)->val>root->val){
                if((*first)==NULL){
                    *first = *temp;
                    *second = root;
                }else{
                    *second = root;
                }
            }
        }
        *temp = root;
        repeat(root->right,temp,first,second);
    }
}
void recoverTree(struct TreeNode* root){ 
    struct TreeNode *temp = NULL, *first = NULL, *second = NULL;
    repeat(root,&temp,&first,&second);
    int swap = first->val;
    first->val = second->val;
    second->val = swap;
    //printf("\n%d and %d\n", first->val, second->val);
}
