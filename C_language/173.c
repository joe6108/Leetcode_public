/*
 * 結果
 * Runtime : 32ms Beats 87.93%of users with C
 * Memory  : 18.37MB Beats 62.07%of users with C
 */
/*
 * 解題思路
 * 利用遍歷去實現inorder排列的同時，用鏈結將答案串起來，就完成了。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct LinkNode {
    int val;
    struct LinkNode* next;
};

struct LinkNode* new_node(int val){
    struct LinkNode* node = malloc(sizeof(struct LinkNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void inorder_root(struct TreeNode* root, struct LinkNode** head, struct LinkNode** tail){   
    if(!root) return;
    inorder_root(root->left, head, tail);
    struct LinkNode* node = new_node(root->val);
    if(!(*head)){
        *head = node;
        *tail = node;
    }else{
        (*tail)->next = node;
        (*tail) = node;
    }
    inorder_root(root->right, head, tail);
}

typedef struct {
    struct LinkNode* head;
    struct LinkNode* start;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = malloc(sizeof(BSTIterator));
    obj->head = NULL;
    obj->start = NULL;
    struct LinkNode* head = NULL;
    struct LinkNode* tail = NULL;
    inorder_root(root, &head, &tail);
    obj->head = head;
    obj->start = head;
    struct LinkNode* temp = head;
    while(temp){
        temp = temp->next;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    int ans = 0;
    if(obj->start){
        ans = obj->start->val;
        obj->start = obj->start->next;
    }
    return ans;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    if(!obj->start) return false;
    return true;
}

void bSTIteratorFree(BSTIterator* obj) {
    struct ListNode* head = obj->head;
    struct ListNode* temp = head;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/