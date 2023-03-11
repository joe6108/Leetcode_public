/*
 * 我使用比較直接的方式，由於要分成兩個區間，但還要遵守他的原先大小順序，所以我就決定直接使用兩個新的串列去區分這兩個區段，
 * 接著在最後去做串接的動作。
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void Node_add(struct ListNode* head, int x){
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = x;
    temp->next = NULL;
    head->next = temp;
}

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *one_l = NULL, *two_l = NULL, *ans = NULL, *two_ans = NULL;
    while(head!=NULL){
        if(head->val < x){
            if(one_l==NULL){
                one_l = malloc(sizeof(struct ListNode));
                one_l->val = head->val;
                one_l->next = NULL;
                ans = one_l;
            }else{
                Node_add(one_l, head->val);
                one_l = one_l->next;
            }
        }else{
            if(two_l==NULL){
                two_l = malloc(sizeof(struct ListNode));
                two_l->val = head->val;
                two_l->next = NULL;
                two_ans = two_l;
            }else{
                Node_add(two_l, head->val);
                two_l = two_l->next;
            }
        }
        head = head->next;
    }
    if(ans==NULL) return two_ans;
    if(two_ans==NULL) return ans;
    if(one_l->next!=NULL) one_l = one_l->next;
    one_l->next = two_ans;
    return ans;
}