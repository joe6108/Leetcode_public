/*
 * 這題也是意外的一次就過了，為了遵守題目提出的限制，我有參考一個網路上的解答方式，如網址: https://home.gamer.com.tw/artwork.php?sn=5537707
 * 不過我只參考了他的解題思路，也就是那張圖所顯示的規律，接著就能很淺顯易懂的方式去解題了，但最主要的還是因為這題是完美二元樹的關係，所以在很多
 * 的地方都不必重視細節。
 */

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
void traver(struct Node* parent, struct Node* kid){
    if(kid==NULL) return;
    //if(parent!=NULL) printf("now parent = %d, now kid = %d\n", parent->val, kid->val);
    if(kid->left!=NULL) kid->left->next = kid->right; // 假設當前節點的左子樹存在時，直接指定左子樹的next為右子樹。
    if(kid->next==NULL){ //假設當前節點是右子樹時。
        if(parent==NULL){ 
            kid->next = NULL;
        }else{ //如果父子樹是存在時，還要判斷其右子樹是否為空，因為只有root的樹頂才會是next為空的狀態，所以要特別判斷。
            if(parent->next==NULL){
                kid->next = NULL;
            }else{ //如果父節點的next存在，這代表當前kid節點不但為右子樹，且next也會是父節點的左子樹。
                //printf("node = %d\n", kid->val);
                kid->next = parent->next->left;
            }
        }
    }
    traver(kid, kid->left);
    traver(kid, kid->right);
}

struct Node* connect(struct Node* root) {
	traver(NULL, root);
    return root;
}