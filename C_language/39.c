/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
解題的想法很簡單，就是用遍歷的方式都搜尋一次，找出需要的答案。

step1 : 先將總和(sum)加上題目給定的陣列的第一項。
step2 : 判斷是否為目標或小於目標，不是則直接捨棄。
step3 : 先判斷是否已經為目標了，不是的話就繼續測試。

會需要使用if(sum == target || sum < target)判斷兩次是因為，我使用動態記憶體分配時，想根據需要而去增加答案的容量，才
會像這樣發生兩次是否為目標的情況發生。

English(by ChatGPT):

The idea of solving the problem is very simple, which is to search for the answer by using a traversal method.

Step 1: First add the first item of the array given by the question to the sum.
Step 2: Check if it is the target or less than the target, if not, simply discard it.
Step 3: First check if it has already reached the target, if not, continue to test.

The reason for using "if (sum == target || sum < target)" to check twice is because when I use dynamic memory allocation, 
I want to increase the capacity of the answer according to my needs, which leads to the occurrence of two situatio
ns where the sum is either the target or not.
*/


void repeat_lookup(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int sum, int n, int*** ans, int* max, int index, int* table){
    sum+=candidates[index];
    if(sum == target || sum < target){
        table[n++] = candidates[index];
        // decide == target?
        if(sum == target){
            (*returnColumnSizes)[*returnSize] = n;
            (*ans)[*returnSize] = (int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                (*ans)[*returnSize][j] = table[j];
            }
            (*returnSize) += 1;
            // limit return array's buffer 
            if((*returnSize) == (*max)){
                (*max)*=2;
                int** tmp = realloc((*ans), sizeof(int*)*(*max));
                if(tmp==NULL){
                    printf("memory realloc fail\n");
                }
                (*ans) = tmp;
                int* tmp2 = realloc((*returnColumnSizes), sizeof(int)*(*max));
                if(tmp2==NULL){
                    printf("memory realloc fail\n");
                }
                (*returnColumnSizes) = tmp2;
            }
        }else{
            for(int i=index;i<candidatesSize;i++){ //from index start, avoid repeat get same int.
                repeat_lookup(candidates,candidatesSize,target,returnSize,returnColumnSizes,sum,n,ans,max,i,table);
            }
        }
        
    }else{
        return;
    }
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    //init
    int sum=0,max=4,n=0;
    int table[20];
    *returnSize = 0;
    int** ans = (int**)malloc(sizeof(int*)*max);
    *returnColumnSizes = (int*)malloc(sizeof(int)*max);
    for(int i=0;i<candidatesSize;i++){
        repeat_lookup(candidates,candidatesSize,target,returnSize,returnColumnSizes,sum,n,&ans,&max,i,table);
    }
    return ans;
}