/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return NULL;
    struct TreeNode* table[1001];
    int head = 0, tail = 0, depth = 0;
    table[tail++] = root;
    while( (tail-head) % 1001 > 0){
        //printf("head = %d, tail = %d, tail - head = %d\n", head, tail, tail - head);
        int range = (tail-head) % 1001;
        for(int i = 0 ; i < range ; i++){
            struct TreeNode* temp = table[head++ % 1001];
            if(temp->left) table[tail++ % 1001] = temp->left;
            if(temp->right) table[tail++ % 1001] = temp->right;
        }
        depth++;
    }
    return depth;
}