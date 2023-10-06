/*
 * 速度 > 100% (並非總是)， 記憶體 > 14.29
 * 這題是出乎意料的一次通過，使用的是跟上題一致的方法，透過上一題的思路，可以知道我只要在確認答案時多下點功夫就能處理了，像是
 * 答案會需要之前經過的路徑，所以我不能只儲存同樣的答案而進入下個遞迴，我需要去紀錄經過的路線，和經過的節點數，接著我就只需要
 * 透過for迴圈計算總合就行了，而剩下的問題在前一題都解決了。
 * 不過我並未考慮到記憶體的分配，所以有一點濫用記憶體的問題。
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
//tem_array : 暫時存放經過的節點 count: 目前取得的節點數 ans: 要回傳的答案二維陣列
void getTarget(struct TreeNode* root, int target, int count, int* temp_array, int** ans, int* returnSize, int** returnColumSizes){
    if(root==NULL) return;
    temp_array[count++] = root->val;
    if(root->left==NULL && root->right==NULL){
        //printf("enter sum\n");
        int sum = 0;
        for(int i=0;i<count;i++) sum+=temp_array[i];
        //printf("sum = %d\n", sum);
        if(sum==target){
            ans[*returnSize] = malloc(sizeof(int)*(count));
            for(int j=0;j<count;j++) ans[*returnSize][j] = temp_array[j];
            (*returnColumSizes)[*returnSize] = count;
            (*returnSize)+=1;
            return;
        }
    }
    getTarget(root->left, target, count, temp_array, ans, returnSize, returnColumSizes);
    getTarget(root->right, target, count, temp_array, ans, returnSize, returnColumSizes);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** ans = malloc(sizeof(int*)*5001);
    *returnColumnSizes = malloc(sizeof(int)*5001);
    if(!root) return ans;
    int* temp_array = malloc(sizeof(int)*5001);
    getTarget(root, targetSum, 0, temp_array, ans, returnSize, returnColumnSizes);
    return ans;
}