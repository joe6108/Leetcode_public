/*
 * 第一版解答，但沒辦法通過，題目要求的是到最後一層的葉子總和為目標值才算true，但我的方法是只要在中途有等於目標值就算通過。
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void count_traver(struct TreeNode* root, int targetSum, int now_sum, bool* result){
    if(root==NULL || *result==true) return;
    now_sum+=root->val;
    if(now_sum == targetSum){
        *result = true;
        return;
    }else if(now_sum > targetSum){
        return;
    }
    count_traver(root->left, targetSum, now_sum, result);
    count_traver(root->right, targetSum, now_sum, result);
    return;
    
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    bool result = false;
    count_traver(root, targetSum, 0, &result);
    return result;
}

/*
 * 第二版，我發覺這題也是單邊子葉和要到最後一層才算，所以我只要將條件嚴格限制在最後的葉子，且這片葉子必須是左右子葉都為NULL才能算數才行，這樣就能同時
 * 解決單邊子葉以及算到最後的問題了。
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void count_traver(struct TreeNode* root, int targetSum, int now_sum, bool* result){
    if(root==NULL || *result==true) return;
    now_sum+=root->val;
    // 前兩個條件用來限定一定要是最後一片葉子才行，第三個條件則為是否為目標值。
    if(root->left==NULL && root->right==NULL && now_sum == targetSum){
        *result = true;
        return;
    }
    count_traver(root->left, targetSum, now_sum, result);
    count_traver(root->right, targetSum, now_sum, result);
    return;
    
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    bool result = false;
    count_traver(root, targetSum, 0, &result);
    return result;
}