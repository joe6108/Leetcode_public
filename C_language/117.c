/*
 * 題目跟上題基本上是一樣的，但就是不限於完美二元樹，不過僅僅這個條件就會讓整個過程差非常多。
 * 使用的方式算是上一題的進階方式，不論在任何節點時，都能有效處理next這個問題。
 * 唯一需要注意的是，如果使用PostOrder的方式時，都必定要從右邊開始遞迴，因為如果從左邊開始，就會遇到父節點的next是空的，導致找不到下一個node的位置。
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
    kid->next = NULL; //預先給予next的值為NULL
    if(parent!=NULL){ 
        if(parent->left==kid && parent->right!=NULL){ //初步判斷是否為當下父節點的左子樹，且判斷父節點的右子樹是否可以當NEXT。
            kid->next = parent->right;
            //printf("success, kid->next = %d\n", kid->next->val);
        }
        if(kid->next==NULL){ //如果初步判斷就有找到next，就不必再從父節點去尋找下個next了，否則會造成初步判斷的next被覆蓋。
            while(parent->next!=NULL){ //由於並不像完美二元樹一樣，所以會遇到像是中間隔了好幾個空節點的狀況，所以需要持續尋找。
                parent = parent->next;
                if(parent->left!=NULL){
                    kid->next = parent->left;
                    //printf("success, kid->next = %d\n", kid->next->val);
                    break;
                }
                if(parent->right!=NULL){
                    kid->next = parent->right;
                    //printf("success, kid->next = %d\n", kid->next->val);
                    break;
                }
            }
        }
    }
    traver(kid, kid->right); //必定從右邊開始找
    traver(kid, kid->left);
}

struct Node* connect(struct Node* root) {
	traver(NULL, root);
    return root;
}