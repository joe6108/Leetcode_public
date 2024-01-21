/*
 * 結果
 * Runtime : 7ms Beats 89.81%of users with C
 * Memory  : 8.04MB Beats 100%of users with C
 */
/*
 * 解題思路
 * 透過三個變數(top頭，middle中，tail尾)從top開始跑，然後只判斷middle是否是目標值，接著再透過判斷是否為首、尾
 * ，再開始做移除以及相接的動作。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* top = head;
    struct ListNode* middle = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* temp = NULL;
    while(top){
        if(middle && middle->val == val){
            temp = middle;
            if(middle == head){
                head = head->next;
            }else{
                tail->next = top;    
            }
            middle = middle->next;
            top = top->next;
            free(temp);
            continue;
        }
        if(middle) tail = middle;
        middle = top;
        top = top->next;
    }
    if(middle && middle->val == val){
        if(!tail){
            head = NULL;
        }else{
            tail->next = NULL;
            free(middle);
        }
    }
    return head;
}