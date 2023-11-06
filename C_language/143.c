/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    struct ListNode* table[50000];
    int index = 0;
    while(head){
        table[index++] = head;
        head = head->next;
    }
    int length = (index - 1) / 2;
    int last = index - 1;
    //printf("%d\n", length);
     for(int i=0;i<length;i++){
         table[i]->next = table[last];
         table[last]->next = table[i+1];
         last--;
    }
    table[last]->next= NULL;
}