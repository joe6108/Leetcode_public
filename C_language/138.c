/*
 * 結果
 * Runtime : 7 ms Beats 74.22%of users with C
 * Memory  : 8.89MB Beats 42.55%of users with C
 */
/*
 * 解題思路
 * 這題需要注意的前提是，每個節點的val值是會重複的，所以沒辦法使用簡單的一維table去找，二維以上就不好說了。
 * 所以這題我是使用比較繞道的方式，也就是先創造新的節點在每個原節點的前方，例如:
 * 1 -> 2 -> 3 -> null 先複製一遍 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> null
 * 為何要先這樣做的原因是因為random，因為random是一種隨機節點，而且也可能會是null，所以我們必須先
 * 解決這個問題，所以我將每個複製完成的節點指向原節點的下一個。
 * 並讓新舊節點的random都指向原節點的random，之後我只要讓新節點的random往前(next)一格，就是新的random位置了。
 * 正因為我讓複製完的節點放在原節點前方，才能這樣完成random的處理。
 * 
 * 再來就只要分離原節點以及新節點就好了，最後就可以解決了。
 * 
 * 總結: 只要想好random怎麼處理，大致上都不會有問題。
 * 
 */

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* create_Node(int val, struct Node* next, struct Node* random){
    struct Node* head = malloc(sizeof(struct Node));
    head->val = val;
    head->next = next;
    head->random = random;
    return head;
}

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    // 將新節點插入原節點前方，並讓random都指向原節點的random。
    while(temp){
        struct Node* new_node = create_Node(temp->val, temp->next, temp->random);
        temp->next = new_node;
        temp = new_node->next;
    }
    // 將random調整至正確位置
    temp = head->next;
    while(temp){
        if(temp->random){
            //printf("temp = %d, temp->random = %d\n", temp->val, temp->random->val);
            temp->random = temp->random->next;
        }
        temp = temp->next;
        if(!temp) break;
        temp = temp->next;
    }
    //分離節點
    temp = head;
    struct Node* ans = temp->next;
    struct Node* temp2 = ans;
    while(temp2->next){
        temp->next = temp2->next;
        temp = temp2;
        temp2 = temp2->next;
    }
    
    return ans;   
}