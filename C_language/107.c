/*
 * 關於這題，我從一開始就想說關於二元樹的三種排列中，其中一項就很適合用來解題，也就是preorder(?)的樣子，使用此種排列就能確保每一層都能從左
 * 至右的順序發現，接著就只需要思考實際上放入數值時的方式了，但在處理這些事情前，我們必須先得出最大深度的數值，因為對於答案來說，他是從下至
 * 上去排列的，關於這點只要看範例輸出就知道了，但在實際處理上，我們不見得會先得到最下層的數值，也就是說得到的答案是不照順序的，那麼我們就得
 * 因此製作一個table表格，紀錄每一層當前得到的數值數量，接著再根據最大深度，確定我們要填入數值的位置。
 * 
 * 只要完成上述的問題點，基本上這題就解決了，接下來該說明的是改進方式，雖說我計算出了最大深度的值，但在每一層的數量上我並沒有根據數量而去做
 * 對應的調整，所以我在這方面都是直接給固定值，也就是假設每層有1000個值，這個方法雖然方便，但極為浪費記憶題，只要完成這點，那這題就算是完美
 * 達成了。
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

void Max_depth(struct TreeNode* root, int level, int* max_depth){
    if(root!=NULL){
        if(level>(*max_depth)) *max_depth = level;
        Max_depth(root->left, level+1, max_depth);
        Max_depth(root->right, level+1, max_depth);
    }
}

void trave_set(struct TreeNode* root, int level, int max_depth, int** ans, int* table){
    if(root!=NULL){
        trave_set(root->left, level+1, max_depth, ans, table);
        trave_set(root->right, level+1, max_depth, ans, table);
        //printf("table[level] = %d, level = %d, max_depth = %d, level = %d, root->val = %d\n", table[level], level, max_depth, level, root->val);
        ans[max_depth-level][table[level]++] = root->val;
    }
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(root!=NULL){
        int max_depth = 0;
        Max_depth(root, 0, &max_depth);
        int** ans = malloc(sizeof(int*)*(max_depth+1));
        (*returnColumnSizes) = malloc(sizeof(int)*(max_depth+1));
        int fix_count = 1000;
        for(int i=0;i<=max_depth;i++) ans[i] = calloc(sizeof(int),fix_count);
        int* table = calloc(sizeof(int),(max_depth+1));
        trave_set(root, 0, max_depth, ans, table);
        *returnSize = max_depth+1;
        for(int i=0;i<=max_depth;i++) (*returnColumnSizes)[i] = table[max_depth-i]; 
        return ans;
    }
    return NULL;
}