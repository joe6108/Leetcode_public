/*
 * 結果
 * Runtime : 345 ms Beats 95.36%of users with C
 * Memory  : 111.25MB Beats 20.53%of users with C
 */
/*
 * 解題思路
 * 利用雙向鏈結去解題，創造快取器時，除了空間之外，會再加上兩個儲存最常被呼叫以及最不常被呼叫的兩個key。
 * 這題就是透過這兩個key去做運算，因為鏈結本身就是順序，也就可以用改變順序的方式去決定誰是最常被呼叫，以及被
 * 最不常呼叫的key是鏈結中的哪個node，也就是尾端以及頭端兩側，剩下的就是透過程式碼去理解實際的運作方式了。
 * 畢竟製作圖表有點麻煩，當只要記住，換位置時，必須要先將目標的node移出鏈結，同時，也要確保鏈結本身的運作
 * 不會因為移出任何node而出問題，接著只要再將node插入鏈結中即可。
 */


struct LRU_Node {
    int key;
    int value;
    struct LRU_Node* next;
    struct LRU_Node* prev;  
};

typedef struct {
    int max_size;
    int now_size;
    struct LRU_Node* key_table[10001];
    struct LRU_Node* head;
    struct LRU_Node* tail;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* new_LRUCache = malloc(sizeof(LRUCache));
    new_LRUCache->max_size = capacity;
    new_LRUCache->now_size = 0;
    for(int i=0;i<10001;i++) new_LRUCache->key_table[i] = NULL;
    new_LRUCache->head = NULL;
    new_LRUCache->tail = NULL;
    return new_LRUCache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(!obj->key_table[key]){
        return -1;
    }
    struct LRU_Node* temp = obj->key_table[key];
    if(temp != obj->head){
        if(temp != obj->tail){
            //對鍊中作處理，將tail移出鏈結
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }else{
            // 透過對尾端的處理，讓tail移出鏈結
            temp->next->prev = NULL;
            obj->tail = temp->next;
        }
        // 再將tail插入head的上方，更新為新的head
        temp->next = NULL;
        //printf("obj->head = %d\n", obj->head->key);
        obj->head->next = temp;
        temp->prev = obj->head;
        obj->head = temp;
    }
    return obj->key_table[key]->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    //printf("get a key = %d, value = %d\n", key, value);
    if(obj->key_table[key]){ //key存在 
        obj->key_table[key]->value = value;
        // 移動到head
        struct LRU_Node* temp = obj->key_table[key];
        if(temp != obj->head){
            if(temp != obj->tail){
                //對鍊中作處理，將tail移出鏈結
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }else{
                // 透過對尾端的處理，讓tail移出鏈結
                temp->next->prev = NULL;
                obj->tail = temp->next;
            }
            // 再將tail插入head的上方，更新為新的head
            temp->next = NULL;
            //printf("obj->head = %d\n", obj->head->key);
            obj->head->next = temp;
            temp->prev = obj->head;
            obj->head = temp;
        }
    }else{
        //創造新的Node
        struct LRU_Node* new_node = malloc(sizeof(struct LRU_Node));
        new_node->key = key;
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = obj->head;
        obj->key_table[key] = new_node; //存入新節點。
        obj->head = new_node;
        if(new_node->prev){
            new_node->prev->next = new_node;
        }else{
            obj->tail = new_node;
        }
        if(obj->now_size == obj->max_size){ //代表容量已滿，將最不常用的刪除。
            struct LRU_Node* temp = obj->tail;
            int del_key = temp->key;
            obj->tail = temp->next;
            temp->next->prev = NULL;
            obj->key_table[del_key] = NULL;
            free(temp);
        }else{
            (obj->now_size)++;   
        }
    }
    //printf("get a key = %d, value = %d success\n", key, value);
}

void lRUCacheFree(LRUCache* obj) {
    struct LRU_Node* head_f = obj->tail;
    while(head_f){
        struct LRU_Node* temp = head_f;
        head_f = head_f->next;
        free(temp); 
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/