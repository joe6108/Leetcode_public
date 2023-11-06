/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head) return 0;
    struct ListNode* ans = NULL;
    struct ListNode* target = head;
    struct ListNode* next = target->next;
    while(next!=NULL && ans==NULL){
        struct ListNode* temp = head;
        if(next==target) ans = next;
        while(temp!=target){
            if(temp==next){
                ans = next;
                break;
            }
            temp = temp->next;
        }
        target = target->next;
        next = next->next;
    }
    return ans;
}