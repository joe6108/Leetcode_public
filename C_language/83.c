/*
 * 我使用的方式是兩段式的處理，假設重複的點開頭就發生了，就跑第一個while迴圈，將重複的點處理掉，例如:
 * 1 1 1 2 2 3 -> 處理掉1的重複項 -> 1 2 2 3 ，之所以這樣做是因為後續的處理處理不到開頭。
 * 接著，開始判斷重複是否發生，直接舉一個例子解釋我做的事情，假設是 1 2 2 2 3 3 4 (處理過開頭)。
 * 那我的重複項發生在(index 2)的位置，那我們就能用link list的做法，將 1 2 ~ 2 2 ~ 3 3 4 ， 其中 ~ 的部分切割掉
 * 讓 1 2 跑到 3 3 4 -> 1 2 3 3 4，讓我們擷取需要的部分。
 * 實際的做法則是 ， 看到 index 1 (2) 等於(==) index 2 (2) ，重複發生，接著從該點持續尋找不等於 index 1 的值的點 -> index 4 (3)，
 * 然後完成切割並繼續做下去。
 * 沒有重複則繼續尋找，完成。
 *
 * 其中版本2是我參考其他人答案寫出來的，是用更簡單的概念完成的。
 */

版本1
------------------------------------------------------------------------------------------------

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head || head->next==NULL) return head;
    struct ListNode *middle = head->next;
    while(middle!=NULL && head->val == middle->val){
        head = head->next;
        middle = middle->next;
    }
    struct ListNode *ans = head;
    while(middle!=NULL){
        if(head->val == middle->val){
            struct ListNode *last = middle;
            while(middle!=NULL && middle->val == head->val) middle = middle->next;
            head->next = middle;
            head = head->next;
            if(middle!=NULL) middle = middle->next;
        }else{
            head = head->next;
        }
    }
    return ans;
}

版本2
----------------------------------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head) return head;
    struct ListNode *start = head, *last = head->next;
    while(last!=NULL){
        if(start->val == last->val){
            start->next = last->next;
            last = last->next;
        }else{
            start = start->next;
            last = start->next;
        }
    }
    return head;
}