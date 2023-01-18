/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
     struct ListNode *next;
};
 */
void List_print(struct ListNode* head){
    while(head!=NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
int List_length(struct ListNode* head){
    struct ListNode* tmp;
    int count = 0;
    while(head!=NULL){
        tmp = head;
        head = head->next;
        count++;
    }
    return count;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* tmp = head;
    struct ListNode* target = NULL; //if list = 1,2,3,4,5 n= 2, then target = 3, head = 4
    int length = List_length(head);
    printf("length = %d\n", length);
    for(int i=0;i<length - n;i++){
        target = head;
        head = head->next;
    }
    if(target!=NULL){ //if target != NULL, then n(head)  in 2~5 . 
        target->next = head->next;
        head->next = NULL;
        free(head);
    }else{ // if target == NULL, then n must = list first node.
        tmp = head->next; 
        free(head);
        return tmp;
    }

    return tmp;
}