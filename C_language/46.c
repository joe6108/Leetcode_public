/*
由於要找出全都不同的組合，我第一個想到的是使用遞迴的方式搜尋，剩下的問題就是邊界條件的關係了，
關於這點，我使用一種紀錄狀態的方式去排除重複的數字(status)，只要是使用過的index就讓設定為使用過，
然後再丟進迴圈遞迴，但要注意的是，丟了之後必須在結束後初始化，為了讓下次歸遞使用。

*/






/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void repeat(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int level, char* table, int*** ans, int* count, char* status){
    if(level==numsSize){
        if((*returnSize)+1==(*count)){
            (*count) = (*count) * 40;
            int** tmp_space = realloc((*ans), sizeof(int*)*(*count));
            if(!tmp_space){
                printf("alloction fail\n");
                exit(1);
            }
            (*ans) = tmp_space;
            int* tp1 = realloc((*returnColumnSizes), sizeof(int)*(*count));
            if(!tp1){
                printf("alloction fail\n");
                exit(2);
            }
            (*returnColumnSizes) = tp1;
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*ans)[*returnSize] = malloc(sizeof(int)*numsSize);
        for(int i=0;i<numsSize;i++){
            (*ans)[*returnSize][i] = table[i];
        }
        (*returnSize)++;
        return;
    }
    for(int i=0;i<numsSize;i++){
        if(status[i] == '1') continue;
        table[level] = nums[i];
        status[i] = '1';
        repeat(nums, numsSize, returnSize, returnColumnSizes, level+1, table, ans, count, status);
        status[i] = '0';
    }
    
    
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int count = 2;
    int** ans = malloc(sizeof(int*)*count); // return's answer
    *returnColumnSizes = malloc(sizeof(int)*count); 
    int* table = malloc(sizeof(int)*numsSize); // get a solution
    *returnSize = 0;
    char* status = malloc(sizeof(int)*(numsSize)); // record used index
    memset(status, '0', numsSize);
    for(int i=0;i<numsSize;i++){
        table[0] = nums[i];
        status[i] = '1';
        repeat(nums, numsSize, returnSize, returnColumnSizes, 1, table, &ans, &count, status);
        status[i] = '0';
    }
    return ans;
    
}