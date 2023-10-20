/*
 * 結果
 * Runtime : 0 ms Beats 100.00%of users with C
 * Memory  : 7.76MB Beats 14.29%of users with C
 */

/*
 * 這題看似複雜，但其實很單純，因為說是複製，但只要創造一個新的記憶體空間，放入相同的值，就算是複製完單個節點了。
 * 比較困難的是順序的問題，因為題目的意思是，任何一個指向的位置是錯誤的，就代表複製失敗，這也就代表順序必須嚴格的遵守。
 * 不過題目有提供val這個順序，也就是說，我們可以利用val提供的順序去排列我們的節點順序，所以我先創造一個陣列去儲存每個複製的新節點。
 * 這樣我就能透過抓取陣列的val相對位置，去確保我有沒有複製過這個節點，以及直接用這個陣列去確保我的順序無誤。
 */

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

//#define NULL (void* )0
struct Node* traver_DFS(struct Node* s, struct Node** table){
    //判斷是否為空節點或複製過
    if(s==NULL) return NULL;
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = s->val;
    newNode->numNeighbors = s->numNeighbors;
    newNode->neighbors = malloc(sizeof(struct Node*) * (s->numNeighbors));
    // 必須先將新的節點放到陣列中，假如到了最後才放上去的話，就會出現重複複製的狀況發生，導致記憶體錯誤。
    table[newNode->val] = newNode;
    for(int i = 0 ; i < s->numNeighbors ; i++){
        struct Node* temp =  s->neighbors[i];
        if(table[temp->val] == NULL){
            newNode->neighbors[i] = traver_DFS(s->neighbors[i], table);
        }else{
            newNode->neighbors[i] = table[temp->val];
        }
    }
    return newNode;
}

struct Node *cloneGraph(struct Node *s) {
    // 儲存複製過的節點 範圍為0~100，所以給101。
    if(s==NULL) return 0;
	struct Node* table[101] = {0}; 
    traver_DFS(s, table);
    return table[1];
}