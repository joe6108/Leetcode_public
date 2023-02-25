/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int List_length(struct ListNode* head){
   int length = 0;
   while(head!=NULL){
        length++;
        head = head->next;
   } 
   return length;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    int len = List_length(head);
    if(len<2 || k%len==0) return head;
    k%=len;
    struct ListNode *ans, *last, *temp;
    temp = head;
    for(int i=0;i<(len-1);i++){
        if(i==(len-k-1)){
            last = temp;
            ans = last->next;
        }
        temp = temp->next;
    }
    temp->next = head;
    last->next = NULL;
    return ans;
}