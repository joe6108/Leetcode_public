/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// swap two node
void List_swap(struct ListNode* head){
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    if(head->next!=NULL){
        l1 = head->next;
        l2 = head->next->next;
        if(l1!=NULL&&l2!=NULL){
            l1->next = l2->next;
            l2->next = l1;
            head->next = l2;
        }
    }
}
// return a length
int List_length(struct ListNode* head){
    int length = 0;
    while(head!=NULL){
        length++;
        head = head->next;
    }
    return length;
}
// 
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* ans = NULL;
    if(!head) return head;
    int length = List_length(head);
    int i;
    if(head->next!=NULL){
        ans = head;
        head = head->next;
        ans->next = head->next;
        head->next = ans; 
    }
    if(ans!=NULL)
        List_swap(ans);

    for(i=0;i<length/2-2;i++){
        if(ans!=NULL){
            ans = ans->next->next;
            List_swap(ans);
        }
    }
    return head;
}