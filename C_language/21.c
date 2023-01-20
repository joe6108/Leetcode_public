/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void List_swap(struct ListNode** list1, struct ListNode** list2){
    struct ListNode* tmp;
    tmp = *list1;
    *list1 = *list2;
    *list2 = tmp;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val > list2->val) List_swap(&list1, &list2); //list1 is min list.
    struct ListNode* new_list = list1; //main_list
    struct ListNode* ans = new_list; //answer
    list1 = list1->next;
    // complete
    while(list1!=NULL&&list2!=NULL){
        if(list1->val <= list2->val){
            new_list->next = list1;
            list1  = list1->next;
        }else{
            new_list->next = list2;
            list2  = list2->next;
        }
        new_list = new_list->next;
    }
    if(list1==NULL) new_list->next = list2;
    if(list2==NULL) new_list->next = list1;

    return ans;
}