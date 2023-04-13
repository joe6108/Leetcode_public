/*
 * 方法一 可以完成9成的部分了，遞迴的順序不符合題目，導致結果有一些放的順序有些相反而已。
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void repeat(struct TreeNode* q, struct TreeNode* p, int* returnSize, int** returnColumnSizes, int level, int** ans){
    //printf("level = %d, returnSize = %d, returnColumnSizes[level] = %d\n",level,*returnSize,(*returnColumnSizes)[level]);
    if(q!=NULL && p!=NULL){
        if(level>=(*returnSize)) (*returnSize) = level+1;
        ans[level][(*returnColumnSizes)[level]++] = q->val;
        ans[level][(*returnColumnSizes)[level]++] = p->val;
        repeat(q->left,p->left,returnSize,returnColumnSizes,level+1,ans);
        repeat(q->right,p->right,returnSize,returnColumnSizes,level+1,ans);
    }else if(q!=NULL){
        if(level>=(*returnSize)) (*returnSize) = level+1;
        ans[level][(*returnColumnSizes)[level]++] = q->val;
        repeat(q->left,p,returnSize,returnColumnSizes,level+1,ans);
        repeat(q->right,p,returnSize,returnColumnSizes,level+1,ans);
    }else if(p!=NULL){
        if(level>=(*returnSize)) (*returnSize) = level+1;
        ans[level][(*returnColumnSizes)[level]++] = p->val;
        repeat(q,p->left,returnSize,returnColumnSizes,level+1,ans);
        repeat(q,p->right,returnSize,returnColumnSizes,level+1,ans);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*11);
    *returnColumnSizes = malloc(sizeof(int)*11);
    memset(*returnColumnSizes,0,sizeof(int)*11);
    *returnSize = 0;
    int amount = 1;
    for(int i=0;i<11;i++){
        ans[i] = malloc(sizeof(int)*amount);
        amount*=2;
    }
    if(root!=NULL){
        *returnSize = 1;
        ans[0][0] = root->val;
        (*returnColumnSizes)[0] = 1;
        repeat(root->left,root->right,returnSize,returnColumnSizes,1,ans);
    }
    return ans;
}

/*
 * 方法二 使用中序排列的方法去解決問題，這樣就能確保順序性。
 *
 * 之後可以改成單個函式完成這個問題。
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void repeat(struct TreeNode* root, int* returnSize, int** returnColumnSizes, int level, int** ans){
    //printf("level = %d, returnSize = %d, returnColumnSizes[level] = %d\n",level,*returnSize,(*returnColumnSizes)[level]);
    if(level>=(*returnSize)){
        (*returnSize) = level;
        ans[level] = malloc(sizeof(int)*2000);
    }
    if(root!=NULL){
        ans[level][(*returnColumnSizes)[level]++] = root->val;
        repeat(root->left,returnSize,returnColumnSizes,level+1,ans);
        repeat(root->right,returnSize,returnColumnSizes,level+1,ans);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ans = malloc(sizeof(int*)*1200);
    *returnColumnSizes = malloc(sizeof(int)*1200);
    memset(*returnColumnSizes,0,sizeof(int)*1200);
    *returnSize = 0;
    //int amount = 1;
    repeat(root,returnSize,returnColumnSizes,0,ans);
    return ans;
}