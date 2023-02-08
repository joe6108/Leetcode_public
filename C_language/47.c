/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
相比前一題，這題需要的更加麻煩，因為多了重複的數字要排除，所以我就以46題的前提下，加入判斷去執行找出答案。
step1 : 在開頭丟入數字前，先將重複的首輸入排除。
step2 : 由於剩下的重複只會發生在字首沒重複的數字，所以條件就會變成，只取第一次重複的數字，剩下則跳過的原則，用例子來看比較簡單。

example : [1,1,2]

step1 ->  1,1,2 1,2,1 2,1,1 2,1,1 剩下2有重複的情況發生，代表我們要處理的是2字首的狀況

step2 ->  處理2開頭， 2,1,1會取得的順序為 index2 -> index0 -> index1 ， 找到後，歸遞會回到上一步繼續找 -> index2 -> index1 -> inedx0

這代表我們要解決歸遞後尋找的重複答案，所以才利用while迴圈讓歸遞不會找到重複的數字 -> index2 -> index0 -> index1 找到後，馬上讓index2的下
一次變成index1 ， 阻止她找到重複數字。

*/
int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void repeat(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int level, char* table, int*** ans, int* count, char* status){
    if(level==numsSize){
        if((*returnSize)+1==(*count)){
            (*count) = (*count) * 4;
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
        while(i+1!=numsSize && nums[i]==nums[i+1]) i++;
    }
    
    
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), comp);
    int count = 2;
    int** ans = malloc(sizeof(int*)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    int* table = malloc(sizeof(int)*numsSize);
    *returnSize = 0;
    char* status = malloc(sizeof(int)*(numsSize));
    memset(status, '0', numsSize);
    for(int i=0;i<numsSize;i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        table[0] = nums[i];
        status[i] = '1';
        repeat(nums, numsSize, returnSize, returnColumnSizes, 1, table, &ans, &count, status);
        status[i] = '0';
    }
    return ans;
    
}

