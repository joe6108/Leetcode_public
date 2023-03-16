/*
 * 這題雖說程式碼很單純，但實際運作上我認為非常麻煩，我邏輯上的考量如下:
 * 
 * 首先，我們可以透過left是否等於1，去將結果分為兩種來表示，以範例來說:
 * 
 * 第一個範例: 1 2 3 4 5 left = 2 right = 4。
 * 
 * 這題的結果為 1 4 3 2 5 。 也就是說，我必須將 2 3 4 倒過來，先讓他變成 4 3 2 ， 接著再將 1 連接到 4 ， 2 再連接到 5 。
 * 
 * 由上面的例子來看，我們需要取得四個點，才能夠完成這一連串的動作，但我覺得這樣的範例不好，因為就這樣來看，你有可能忘記取得開頭的位置，再舉一個例子:
 * 
 * 1 2 3 4 5 6 7 left = 3 right = 5 。 答案為 1 2 5 4 3 6 7 。 從這題來看會比較清楚處理的方式，接下來按照步驟來處理:
 * 
 * stpe1 : 找到需要處理的四個點，1 -> 2 3 4 5 6 <- 7 ， 箭頭內的必須倒過來，完成我們需要的部分。所以我們實際上要得到的是五個點，包含最後的答案。
 * 
 * step2 : 1 -> 2 5 4 3 6 <- 7 ， 接著將 2->next = 5 ， 3->next = 6 。 
 * 
 * step3 : 完成。 可以將此例子帶入我的程式碼 ans = 1 , first_node = 2 , third_node = 5 , temp_node = 3 , head = 6 。
 * 
 * 這就是我們處理left不是1時的方式。
 * 
 * 接著我們來看下個範例: 5 left = 1 right = 1 。 很顯然的，他根本不會改變，所以當left==right就可以回傳答案了。
 * 
 * 最後要處理的就是left==1的情況了，之所以會分成這兩種，主要是因為回傳的頭(ans)是不一樣的，舉一個例子:
 * 
 * 1 2 3 4 5 left = 1 right = 5 
 * 
 * 答案為 5 4 3 2 1 ， 答案根本就是倒過來了吧，那我要回傳的反而是5的位置(temp)，但也就這樣，這題就完成了。
 * 
 * 剩下的就是看懂我的程式碼了。
 */







/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left==right) return head;
    struct ListNode* ans = head, *first_node = head, *two_node = NULL;
    struct ListNode *temp = NULL, *third_node = NULL;
    for(int i=1;i<=right;i++){
        if(i>left){ //將兩者的順序顛倒 1->2->3 變成　1<-2 3 。(代表2跟3就段開了)，
            temp = head; //隨時得到第三個點的位置
            head = head->next; //最後一個點的位置
            temp->next = third_node;
            third_node = temp;
        }else if(i==left){ // 開始記錄第二個點的位置
            two_node = head;
            third_node = head;
            head = head->next;
        }else{
            first_node = head; //隨時更新第一個點的位置
            head = head->next;
        }
    }
    if(left==1){
        two_node->next = head;
        return temp;
    }
    two_node->next = head;
    first_node->next = third_node;
    return ans;
}
