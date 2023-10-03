/*
 * 第一版，誤會高平衡樹的定義所寫，參考條件為:
   1. 最深及最淺的層數相差不能大於1
   2. 每個節點都必須有相對的左子樹及右子樹，也就是同為NULL或同時有其他節點。
   但答案的定義為: 左子樹和右子樹相差不能大於1而已。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int traver_root(struct TreeNode* root, bool* ans, int* min_depth, int* max_depth, int depth){
    if(*ans){
        if(root!=NULL){
            /*
            if((root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL)){
                *ans = false;
            }
            */
            traver_root(root->left, ans, min_depth, max_depth, depth+1);
            traver_root(root->right, ans, min_depth, max_depth, depth+1);
        }else{
            if((*min_depth)==-1){
                *min_depth = depth;
            }else{
                if(depth < (*min_depth)) *min_depth = depth;
            }
            if((*max_depth)==-1){
                *max_depth = depth;
            }else{
                if(depth > (*max_depth)) *max_depth = depth;
            }
        }
    }
    return 0;
}

bool isBalanced(struct TreeNode* root){
    bool ans = true;
    int min_depth = -1;
    int max_depth = -1;
    if(!root) return true;
    traver_root(root, &ans, &min_depth, &max_depth, 0);
    printf("max = %d, min = %d", max_depth, min_depth);
    if((max_depth - min_depth) > 1) ans = false;
    return ans;
}


/*
 * 第二版本
 * 思路更換成計算每個節點的左子樹以及右子樹的最高深度是否相差大於1，由於我本身沒想出來，所以方法是套用chargpt的方法。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 計算樹的高度
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int l_depth = height(root->left);
    int r_depth = height(root->right);
    int max = l_depth;
    if(r_depth > max) max = r_depth;
    return max+1;
}


bool isBalanced(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    // 如果左子樹和右子樹的高度差超過1，則不是平衡二叉樹
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    // 遞歸檢查左子樹和右子樹是否都是平衡二叉樹
    return isBalanced(root->left) && isBalanced(root->right);
}