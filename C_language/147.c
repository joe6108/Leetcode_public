/*
 * 結果
 * Runtime : 28 ms Beats 65.13%of users with C
 * Memory  : 8.15MB Beats 5.04%of users with C
 */
/*
 * 解題思路
 * 主要是參照題目的範例去寫的，我是以從頭開始建立一條新的List之後，再去使用插入法解決這個題目。
 * 比較特別的是，題目是從後面開始比大小，選擇插入的點，但我們只能從開頭開始，所以我們就是每次從head取出
 * 一個數值之後，對新的list的開頭一個一個的比大小，接著按照我們當下節點以及prev(前一個節點)
 * 去判斷插入的位置，決定是否要插入list中，抑或是讓得到的head數值去當新的頭(最前點)，抑或是尾巴(最後點)。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* new_head = NULL;
    struct ListNode* prev = NULL;
    while(head){
        struct ListNode* new_node = malloc(sizeof(struct ListNode));
        new_node->val = head->val;
        new_node->next = NULL;
        if(!new_head){
            new_head = new_node;
        }else{
            struct ListNode* temp = new_head;
            prev = NULL;
            while(temp){
                if(head->val <= temp->val){
                    if(prev==NULL){
                        new_node->next = new_head;
                        new_head = new_node;
                    }else{
                        prev->next = new_node;
                        new_node->next = temp;
                    }
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if(!temp){
                prev->next = new_node;
            }
        }
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return new_head;
}