/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * 利用前一題得出的函式，先確認樹的兩側結構是否對稱，如果不對稱則直接回傳false。
 * 上面是第一步。
 * 接下來就是要確認數字是否對稱，我使用了兩個陣列去分別儲存兩側樹的數值順序，因為應該要是對稱，所以一個可以用由小到大的排列，另一個則是由大到小。
 * 最後只要順便紀錄任一側有多少個node，就可以根據這個數量去使用迭代for迴圈去檢查兩個陣列是否相等。
 * 以上就是所有的步驟。
 *
 */

bool repeat(struct TreeNode* q, struct TreeNode* p, int* count, int* q_arr, int* p_arr){
    if(q==NULL && p==NULL) return true;
    if(q==NULL || p==NULL) return false;
    //printf("%d-> q=%d, p=%d\n", *count, q->val, p->val);
    q_arr[*count] = q->val;
    p_arr[*count] = p->val;
    (*count)++;
    return repeat(q->left,p->right,count,q_arr,p_arr) && repeat(q->right,p->left,count,q_arr,p_arr);
}
bool isSymmetric(struct TreeNode* root){
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL || root->right==NULL) return false;
    int* q_arr = malloc(sizeof(struct TreeNode)*501);
    int* p_arr = malloc(sizeof(struct TreeNode)*501);
    int count = 0;
    if(!repeat(root->left,root->right,&count,q_arr,p_arr)) return false;
    //printf("count = %d\n",count);
    for(int i=0;i<count;i++){
        //printf("q=%d, p=%d\n", q_arr[i],p_arr[i]);
        if(q_arr[i]!=p_arr[i]) return false;
    }
    return true;
}