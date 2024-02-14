/*
 * 結果
 * Runtime : 13ms Beats 86.15%of users with C
 * Memory  : 12.60MB Beats 40.00%of users with C
 */
/*
 * 解題思路
 * 將這題以網路拓樸或拓樸排序法的方式去思考，可以將這題視作在畫圖，也就是沒有規則，多個起點，多個終點的順序圖。
 * 所以我的解決方法是透過為每個點對點的起點創造一個node，賦予其val，有多少個下個位置，儲存下個位置的table，三個
 * 變數，所以我們會先創造一個table，儲存每個起始點的記憶體位置(多個起點)，接著再透過node的table(多個終點)。
 * 解決問題，將所有點的順序都排好之後，我們就能從每個起點去循環遍歷結果，找到環狀(無限循環)的節點，就
 * 回傳false，如果沒有則回傳true。
 * 找到環狀的理由就是題目要求的，當擋修發生了矛盾時，就要回傳false，也就是明明要 1->0 0->2 卻遇到了 2->1 的
 * 矛盾情形發生，不過這樣子仍舊會發生time out的狀況，所以我又多創建了一個table去紀錄尋找過的node，以及
 * 尋找的當下是否有發生循環的table，利用這利用這兩個Table去大量減少dps搜尋的時間，就是答案了。
 */

struct Link{
    int val;
    int total;
    struct Link* Link_Link_Table[50];
};

struct Link* create_Node(){
    struct Link* newNode = malloc(sizeof(struct Link));
    newNode->val = 0;
    newNode->total = 0;
    for(int i=0;i<50;i++) newNode->Link_Link_Table[i] = NULL;
    return newNode;
}

void dps_search(struct Link* head, bool* dp_table, bool* check_table, bool* result){
    if(*result){
        //printf("head = %d\n", head->val);
        for(int i=0;i<head->total;i++){
            if(dp_table[head->Link_Link_Table[i]->val]){
                *result = false;
                break;
            }else{
                if(check_table[head->Link_Link_Table[i]->val]){
                    continue;
                }else{
                    check_table[head->Link_Link_Table[i]->val] = true;
                }
                dp_table[head->Link_Link_Table[i]->val] = true;
                dps_search(head->Link_Link_Table[i], dp_table, check_table, result);
                dp_table[head->Link_Link_Table[i]->val] = false;
            }
        }
    }
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    if(numCourses == 1 || prerequisitesSize<2) return true;
    bool* dp_table = calloc(numCourses, sizeof(struct Link*));
    bool* check_table = calloc(numCourses, sizeof(struct Link*));
    struct Link** Link_table = calloc(numCourses, sizeof(struct Link*));
    struct Link* temp = NULL;
    for(int i=0;i<prerequisitesSize;i++){
        if(Link_table[prerequisites[i][0]] == NULL){
            temp = create_Node();
            temp->val = prerequisites[i][0];
            Link_table[prerequisites[i][0]] = temp;
        }
        if(Link_table[prerequisites[i][1]] == NULL){
            temp = create_Node();
            temp->val = prerequisites[i][1];
            Link_table[prerequisites[i][1]] = temp;
        }
        temp = Link_table[prerequisites[i][0]];
        temp->Link_Link_Table[temp->total++] = Link_table[prerequisites[i][1]];
    }
    bool result = true;
    for(int i=0;i<numCourses;i++){
        if(Link_table[i] && check_table[i] == false){
            check_table[i] = true;
            dp_table[i] = true;
            dps_search(Link_table[i], dp_table, check_table, &result);
            if(result == false) break;
            dp_table[i] = false;
        }
    }
    for(int i=0;i<numCourses;i++){
        if(Link_table[i]){
            free(Link_table[i]);
        }
    }
    free(dp_table);
    free(check_table);
    free(Link_table);
    return result;
}