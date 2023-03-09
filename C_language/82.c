/*
 * 這題使用的方式類似83題的版本1，後續的方法無法處理開頭，所以使用第一個迴圈去過濾所有有發生重複的數值。
 * 例子: 1 1 1 2 2 3 3 4 5 6 6 6 7 7 7 8 9 ， 經過第一個迴圈 -> 4 5 6 6 6 7 7 7 8 9
 * 從這裡就能夠確保第一個值絕對是非重複值。
 * 接著要判斷後續是否有重複的值，就要使用第二個迴圈了，這裡我用的方式是一次檢驗三個值，但檢驗的前提為這個link還擁有三個或以上的值存在。
 * 這裡給這三個值分別為1(index0) 2(index1) 3(index2)編號，每次先檢驗2跟3，當2跟3重複時，讓1連接到3的下一個位置。
 * 舉一個例子，假設是1 2 2 2 ， 那麼 1 2 2 2 -> 1 2 ，這是link的變化，這邊會發現，重複的值沒有刪乾淨，所以要馬上將編號2,3往後推一格，
 * 變成(index2) -> 2 (index3) -> 2 ， 又會馬上發現重複，再把編號1接到編號3(index3)之後 -> 1 NULL ， 這樣問題就解決了。
 * 但除此之外還有一種就是 1 2 2 3 3 的題型，但這個問題，只要在結束上述方式的方法後，直接將編號2,3往後推即可。
 * 最後就是head的前進，只要沒找到重複就讓head(編號1)前進就行了。
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    //printf("\n------------\n");
    if(head == NULL) return head;
    struct ListNode *temp = head->next;
    while(temp!=NULL && head->val == temp->val){
        while(temp!=NULL && head->val == temp->val){
            head = head->next;
            temp = temp->next;
        }
        head = head->next;
        if(temp!=NULL) temp = temp->next;
    }
    struct ListNode* ans = head, *last = NULL;
    if(head!=NULL){
        temp = head->next;
        if(temp!=NULL) last = temp->next;
        while(temp!=NULL){
            //printf("%d\n", head->val);
            if(last!=NULL && temp->val == last->val){
                while(last!=NULL && temp->val == last->val){
                    head->next = last->next;
                    temp = temp->next;
                    if(temp!=NULL) last = last->next;
                }
            }else{
                head = head->next;
            }
            temp = temp->next;
            if(temp!=NULL) last = last->next;
        }
    }

    return ans;
}