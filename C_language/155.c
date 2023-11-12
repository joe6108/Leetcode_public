/*
 * 結果
 * Runtime : 19 ms Beats 94.41%of users with C
 * Memory  : 16.54 MB Beats 28.82%of users with C
 */
/*
 * 解題思路
 * 這題最大的問題就是要在O(1)時間複雜度內取得最小值(min)，但這個的解決方法非常簡單，只要想像一下在每次
 * 堆疊一個新的stack時，都找出一個到目前這個高度時的最小值是誰，就可以了，所以我們只要在每次堆疊的數值中
 * 再加上一個min去紀錄到當前層數時的最小值是誰，就不用擔心pop取出會改變min的問題了，而每次的min決定，都
 * 只要透過新的stack和下面的stack記錄中的的最小值是誰做比較，就可以得出新的stack的最小值是誰了。
 */

struct Stack_Node{
    int val;
    int min;
};

typedef struct {
    int top;
    struct Stack_Node* A[10000];
} MinStack;


MinStack* minStackCreate() {
    MinStack* new_stack = malloc(sizeof(MinStack));
    new_stack->top = -1;
    for(int i=0;i<10000;i++) new_stack->A[i] = NULL;
    return new_stack;
}

void minStackPush(MinStack* obj, int val) {
    struct Stack_Node* new_node = malloc(sizeof(struct Stack_Node));
    new_node->val = val;
    if(obj->top==-1){
        new_node->min = val;
    }else{
        struct Stack_Node* temp = obj->A[obj->top];
        if(val < temp->min){
            new_node->min = val;
        }else{
            new_node->min = temp->min;
        }
    }
    obj->A[++(obj->top)] = new_node;
}

void minStackPop(MinStack* obj) {
    if(obj->top==-1){
        printf("error\n");
        exit(1);
    }
    struct Stack_Node* temp = obj->A[(obj->top)--];
    free(temp);
}

int minStackTop(MinStack* obj) {
    if(obj->top==-1){
        printf("error\n");
        exit(1);
    }
    struct Stack_Node* temp = obj->A[obj->top];
    return temp->val;
}

int minStackGetMin(MinStack* obj) {
    if(obj->top==-1){
        printf("error\n");
        exit(1);
    }
    struct Stack_Node* temp = obj->A[obj->top];
    return temp->min;
}

void minStackFree(MinStack* obj) {
    while(obj->top!=-1){
        struct Stack_Node* temp = obj->A[(obj->top)--];
        free(temp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/