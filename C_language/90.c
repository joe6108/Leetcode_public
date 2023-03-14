/*
 * 我使用的方式基本上就跟第一版的題目一樣，用遍歷的方式搜尋，也就是倒退搜尋法?
 * 但比較不同的是這題會有重複項的出現，所以我們需要去過濾掉重複的答案，只追求需要的。
 * 那我所用的方式就是先將陣列弄成非遞減的形式，接著就可以由小到大的方式搜尋，舉一個例子就如 2 2 1 1 。
 * 經過排列後會變成 1 1 2 2 ， 接著我們每次都會限制答案的最大數量，假設我們需要的答案大小為2，代表我們只需取兩個數字。
 * 那我的答案勢必只有 1 1 , 1 2 , 2 2 這三種，如果我們使用原來的方式，我們會得到 : 1 1 , 1 2 , 1 2 , 1 2 , 1 2 , 2 2 。
 * 我第一次使用的方式是只要看到重複的就跳過，但這個方式還不能完美的解決，實際操作如下:
 * step1 : 看到index0 == index1 跳過 -> 取得index1 -> 1 。
 * step2 : 看到index2 == index3 跳過 -> 取得index3 -> 2 。
 * 可是你會發現這個方法跳過了1 1 這個答案，代表還不能夠完成這題。
 * 這時我使用了另一種方式
 * 第二個方式: 第一次任意取得重複項，但第二次開始就跳過所有重複項。
 * 聽起來很難懂，實際操作如下:
 * step1 : 看到index0 ， 直接取得 -> index0 -> 1 ， 取得之後，再開始看到重複的就跳過，index0 == index1 跳過，(下次開始的for迴圈還會+1，所以會取得index2->2)。
 * step2 : 看到index1 ， 直接取得 -> index1 -> 1 ， 取得之後，同上。
 * 這樣我們就能夠取得重複項，這個方式比較需要去了解遍歷的實際行為比較好理解，但這邊就不補充了。
 * 
 * 
 * 
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int repeat(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ans, int* table, int level, int max_level, int next_index){
    if(level==max_level){
        ans[*returnSize] = malloc(sizeof(int)*max_level);
        (*returnColumnSizes)[*returnSize] = max_level;
        for(int i=0;i<max_level;i++) ans[*returnSize][i] = table[i];
        (*returnSize)++;
        return;
    }
    for(int i=next_index;i<numsSize;i++){
        table[level] = nums[i];
        repeat(nums, numsSize, returnSize, returnColumnSizes, ans, table, level+1, max_level, i+1);
        while(i+1<numsSize && nums[i]==nums[i+1]) i++;
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,Max_size = 10000;
    int **ans = malloc(sizeof(int*)*Max_size);
    (*returnColumnSizes) = malloc(sizeof(int)*Max_size); 
    (*returnColumnSizes)[0] = NULL;
    int table[numsSize];
    *returnSize = 1;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(i=1;i<=numsSize;i++){
        repeat(nums, numsSize, returnSize, returnColumnSizes, ans, table, 0, i, 0);
    }
    return ans;
}