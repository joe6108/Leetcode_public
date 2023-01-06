/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addnum(struct ListNode** list1, struct ListNode** list2){
    struct ListNode* l1 = *list1;
    struct ListNode* l2 = *list2;
    struct ListNode* tmp;
    int sum, next = 0;
    while(l1!=NULL){
        while(l2!=NULL){
            sum = l1->val + l2->val + next;
            if(sum >= 10){
                next = 1;
                l1->val = sum % 10;
            }else{
                next = 0;
                l1->val = sum;
            }
            l2 = l2->next;
            tmp = l1;
            l1 = l1->next;
        }
        if(l1==NULL)
            break;
        sum = l1->val + next;
        if(sum >= 10){
            next = 1;
            l1->val = sum % 10;
        }else{
            next = 0;
            l1->val = sum;
        }
        tmp = l1;
        l1 = l1->next;
    }
    if(next == 1){
        struct ListNode* last_node = NULL;
        last_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = last_node;
        last_node->val = 1;
        last_node->next = NULL;
    }
    return tmp;

}

void swap(struct ListNode** l1, struct ListNode** l2){
    struct ListNode* temp = NULL;
    temp = *l1;
    *l1 = *l2;
    *l2 =  temp;
}

int printLen(struct ListNode* list){
    int length = 0;
    while(list!=NULL){
        length+=1;
        list = list->next;
    }
    return length;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    int l1_length = printLen(l1);
    int l2_length = printLen(l2);
    int sum = 0;
    int next = 0;
    int i = 0;
    int change = l2_length > l1_length ?  1 : 0;
    if(change == 1)
        swap(&l2, &l1);
    addnum(&l1, &l2); 
    return l1;  
}

