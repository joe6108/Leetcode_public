/*
 * 結果
 * Runtime : 463 ms Beats 5.18%of users with C
 * Memory  : 19.72MB Beats 85.14%of users with C
 */
/*
 * 解題思路
 * 同上一題的方法，只是為了省記憶體，所以從原有的list開始切割並排列。
 * 但從頭開始做的話實在太慢，所以每次做完一個節點的插入之後，都會在下次的迴圈中比較新拿的跟上一個插入的節點做比較，
 * 如果上一個節點的值已經小於新的節點值了，那就直接從上一個節點的位置開始進迴圈就好。
 * 
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode* first_head = head;
    struct ListNode* secord_head = head->next;
    struct ListNode* prev = NULL;
    struct ListNode* last_first_head = NULL;
    first_head->next = NULL;
    
    while(secord_head){
        // temp_secord list
        struct ListNode* temp_secord_head = secord_head;
        secord_head = secord_head->next;
        temp_secord_head->next = NULL;
        // temp_first list
        prev = NULL;
        struct ListNode* temp_first_head = first_head;
        if(last_first_head){
            if(last_first_head->val < temp_secord_head->val){
                temp_first_head = last_first_head;
            }
        }
        while(temp_first_head){
            if(temp_secord_head->val <= temp_first_head->val){
                if(!prev){
                    temp_secord_head->next = temp_first_head;
                    first_head = temp_secord_head;
                }else{
                    prev->next = temp_secord_head;
                    temp_secord_head->next = temp_first_head;
                }
                break;
            }
            prev = temp_first_head;
            temp_first_head = temp_first_head->next;
        }
        if(!temp_first_head){
            prev->next = temp_secord_head;
        }
        //last_enter
        last_first_head = temp_secord_head;
    }
    return first_head;
}

// 失敗的解法1，耗時太久。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode* first_head = head;
    struct ListNode* secord_head = head->next;
    struct ListNode* prev = NULL;
    first_head->next = NULL;
    
    while(secord_head){
        //printf("secord_head = %d\n", secord_head->val);
        //printf("first_head = %d\n", first_head->val);
        // temp_secord list
        struct ListNode* temp_secord_head = secord_head;
        secord_head = secord_head->next;
        temp_secord_head->next = NULL;
        // temp_first list
        struct ListNode* temp_first_head = first_head;
        prev = NULL;
        while(temp_first_head){
            //printf("temp_first_head = %d\n", temp_first_head->val);
            if(temp_secord_head->val <= temp_first_head->val){
                if(!prev){
                    temp_secord_head->next = temp_first_head;
                    first_head = temp_secord_head;
                }else{
                    prev->next = temp_secord_head;
                    temp_secord_head->next = temp_first_head;
                }
                break;
            }
            prev = temp_first_head;
            temp_first_head = temp_first_head->next;
        }
        if(!temp_first_head){
            prev->next = temp_secord_head;
        }
    }
    return first_head;
}