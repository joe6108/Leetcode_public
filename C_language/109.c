/*
 * 方式是仿照前一題的做法，應用在這題上，其中比較特別的是在搜尋右子樹的時候，我將原本搜尋到的位置繼承至下一輪，讓搜尋右子樹的時間大幅下降。
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* Sort_Traver(int start_pos, int end_pos, struct ListNode* head){
    //printf("start_pos = %d, end_pos = %d\n", start_pos, end_pos);
    if(start_pos > end_pos) return NULL;
    int val = (end_pos + start_pos) / 2 ;
    struct ListNode* middle = head;
    for(int i=start_pos; i< val; i++) middle = middle->next;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    //printf("val = %d\n", middle->val);
    root->val = middle->val;
    root->left = Sort_Traver(start_pos, val - 1, head);
    root->right = Sort_Traver(val + 1, end_pos, middle->next);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    struct ListNode* temp = head;
    int node = 0;
    while(temp!=NULL){
        node++;
        temp = temp->next;
    }
    return Sort_Traver(0, node-1, head);
}