/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head) return false;
    //if(head->next==head) return true;
    //if(head->next==NULL) return false;
    struct ListNode* target = head;
    struct ListNode* next = target->next;
    bool ans = false;
    while(next!=NULL && ans==false){
        struct ListNode* temp = head;
        if(next==target) ans = true;
        while(temp!=target){
            if(temp==next){
                ans = true;
                break;
            }
            temp = temp->next;
        }
        target = target->next;
        next = next->next;
    }
    return ans;
}