/*
 * 結果
 * Runtime : 0ms Beats 100.00%of users with C
 * Memory  : 6.48MB Beats 65.26%of users with C
 */
/*
 * 解題思路
 * 透過三個節點變數做接點的變化就是答案了。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head || head->next==NULL) return head;
    struct ListNode *tail = NULL, *middle = head, *first = middle->next;
    while(middle){
        if(first == NULL){
            middle->next = tail;
            break;
        }else{
            if(tail == head){
                tail->next = NULL;
            }
            middle->next = tail;
        }
        tail = middle;
        middle = first;
        first = first->next;
    } 
    return middle;
}