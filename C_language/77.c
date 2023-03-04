/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
 * 這題我的解決辦法是一次性的取得所有答案，所循序的邏輯就是按照人會如何尋找解答，就讓程式模仿即可。
 * 因為用打字不太好解釋，直接帶例子下去:
 * example1 : n=4 , k=2  ->  1 2 3 4 ， 人類的找法: 1 2 -> 1 3 -> 1 4 -> 2 3 -> 2 4 -> 3 4 
 * example2 : n=5 , k=3  ->  1 2 3 4 5 -> 123 -> 124 -> 125 -> 134 -> 135 -> 145 -> 234 -> 235 -> 245 -> 345 代一下公式確認答案 C 5 取 3
 * --> 5階 / 3階*2階 = 10 剛好符合答案，從中可以發現我們在找答案時，都是從最左固定k-1個位數，開始逐個尋找，那我只要讓程式重複這過程即可。
 * 所以我使用的方式就是遍歷，以結果來說只要一個迴圈即可完成這題。
 * 我的解題方式是先不考慮記憶體的部分所做的，這題是可以做到記憶體分配剛剛好的，但由於不太難就專注於解題上了。 
 */

#define MaxSize 10000

int repeat(int n, int k, int* returnSize, int** returnColumnSizes, int** ans, int* table, int level, int next){
    //printf("level = %d\n", level);
    if(level==k){
        //printf("open");
        ans[*returnSize] = malloc(sizeof(int)*k);
        (*returnColumnSizes)[*returnSize] = k;
        for(int i=0;i<k;i++) ans[*returnSize][i] = table[i];
        (*returnSize)++;
        return;
    }
    for(int i=next;i<=n;i++){
        table[level] = i;
        repeat(n, k, returnSize, returnColumnSizes, ans, table, level+1, i+1);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int*)*MaxSize);
    *returnColumnSizes = malloc(sizeof(int)*MaxSize);
    *returnSize = 0;
    int *table = malloc(sizeof(int)*(k)); 
    repeat(n, k, returnSize, returnColumnSizes, ans, table, 0, 1);
    return ans;
}