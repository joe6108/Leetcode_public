/*
 * 結果
 * Runtime : 5ms Beats 71.62%of users with C
 * Memory  : 6.80MB Beats 60.81%of users with C
 */
/*
 * 解題思路
 * 參考網路上其他人的方式
 * https://medium.com/@ChYuan/leetcode-no-179-largest-number-%E5%BF%83%E5%BE%97-medium-e578b1d9b89e
 * 透過特別的排列方式去排列出答案。
 */

int cmp(const void *a, const void *b){
    int n1 = *(int*)a;
    int n2 = *(int*)b;
    if(n1==0) return 1;
    if(n2==0) return -1;
    char n1_table[20] = {0};
    char n2_table[20] = {0};
    int n1_len = 0, n2_len = 0;
    while(n1!=0){
        n1_table[n1_len++] = n1 % 10 + '0';
        n1 /= 10; 
    }
    while(n2!=0){
        n2_table[n2_len++] = n2 % 10 + '0';
        n2 /= 10; 
    }
    for(int j=0;j<n2_len;j++){
        n1_table[n1_len+j] = n2_table[j];
    }
    for(int j=0;j<n1_len;j++){
        n2_table[n2_len+j] = n1_table[j];
    }
    n1_len+=n2_len;
    for(int j=n1_len-1;j>=0;j--){
        if(n1_table[j] != n2_table[j]){
            if(n1_table[j] < n2_table[j]){
                return -1;
            }else{
                return 1;
            }
        }
    }

    return 0;
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    char* ans = calloc(1000, sizeof(char));
    int len = 0, index = 0, temp = 0, zero = 0;
    char table[20] = {0};
    for(int i=0;i<numsSize;i++){
        //printf("%d\n", nums[i]);
        if(nums[i]==0){
            zero++;
            continue;
        }
        len = 0;
        while(nums[i]!=0){
            table[len++] = nums[i] % 10 + '0';
            nums[i] /= 10; 
        }
        temp = index + len;
        for(int j=len-1;j>=0;j--){
            ans[index+len-1-j] = table[j]; 
        }
        index = temp;
    }
    for(int i=0;i<zero;i++){
        ans[index] = '0';
        if(index==0) break;
        index++;
    }
    return ans;
}








// 失敗的版本1 。 
// 錯誤題目: 34323 , 3432
struct LinkNode{
    int len;
    char str[11];
    struct LinkNode* next;
};
char* largestNumber(int* nums, int numsSize) {
    int tail = 0, total = 0, l1_len = 0, l2_len = 0;
    struct LinkNode* head = NULL;
    struct LinkNode* end = NULL;
    struct LinkNode* last = NULL;
    struct LinkNode* temp = NULL;
    for(int i = 0 ; i < numsSize ; i++){
        struct LinkNode* new_node = malloc(sizeof(struct LinkNode));
        //初始化
        new_node->len = 0;
        for(int j = 0 ; j < 11 ; j++) new_node->str[j] = 0;
        new_node->next = NULL;
        //將值放入陣列並計算長度
        while(nums[i]!=0){
            new_node->str[(new_node->len)++] = (nums[i] % 10) + '0';
            nums[i] /= 10; 
        }
        new_node->str[new_node->len] = '\0';
        //長度將為strlen的長度 如12的len = 2。
        total += new_node->len;
        tail = new_node->len - 1;
        bool get_ans = false;
        //printf("new is %d i = %d\n", nums[i], i);
        if(!head){
            head = new_node;
            end = new_node;
        }else{
            get_ans = false;
            temp = head;
            while(temp){
                l1_len = new_node->len - 1;
                l2_len = temp->len - 1;
                while(1){
                    //printf("l1_len = %d, l2_len = %d, l1 = %c, l2 = %c\n", l1_len, l2_len, new_node->str[l1_len], temp->str[l2_len]);
                    if(new_node->str[l1_len] > temp->str[l2_len]){
                        if(temp == head){
                            new_node->next = temp;
                            head = new_node;
                        }else{
                            new_node->next = temp;
                            last->next = new_node;
                        }
                        get_ans = true;
                        break;
                    }else if(new_node->str[l1_len] < temp->str[l2_len]){
                        if(temp == end){
                            temp->next = new_node;
                            end = new_node;
                            get_ans = true;
                            break;
                        }
                    }
                    if(l1_len == 0 && l2_len == 0){
                        if(temp == head){
                            new_node->next = temp;
                            head = new_node;
                        }else{
                            new_node->next = temp;
                            last->next = new_node;
                        }
                        get_ans = true;
                        break;
                    }
                    if(l1_len > 0) l1_len--;
                    if(l2_len > 0) l2_len--;
                }
                if(get_ans) break;
                last = temp;
                temp = temp->next;
            }
        }
    }
    char* ans = calloc(total+1, sizeof(char));
    ans[total] = '\0';
    int index = 0;
    temp = head;
    while(temp){
        for(int i = temp->len-1; i>=0; i--){
            ans[index++] = temp->str[i];
        }
        temp = temp->next;
    }
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
    return ans;
}