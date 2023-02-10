
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/*
透過計算ASCII碼的方式取得答案，使用這樣的方式可以解決9成的狀況，剩下的1成則是有多個總和相等的組合，這時就使用click這個函式去創造一個table，
然後去對應字元做確認，找出正確的答案，最後再回傳陣列。
*/
#define SIZE 10000

int click(char* array1, char* array2, int length){
    int i, j, count;
    bool* temp = malloc(sizeof(bool)*length);
    memset(temp, 0, length*sizeof(bool));
    for(i=0;i<length;i++){
        count = 0;
        for(j=0;j<length;j++){
            if(array1[i]==array2[j] && temp[j]==0){
                temp[j]=1;
                break;
            }else{
                count++;
            }
        }
        if(count==length) return 1;
    }
    return 0;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char*** ans = malloc(sizeof(char**)*SIZE);
    ans[0] = malloc(sizeof(char*)*SIZE);
    *returnColumnSizes = calloc(sizeof(int),SIZE);
    *returnSize = 0;
    int* table = malloc(sizeof(int)*strsSize);
    int i,j,k,length,count=0,key=0;

    for(i=0;i<strsSize;i++){
        count = 0;
        length = strlen(strs[i]);
        for(j=0;j<length;j++) count+=(int)strs[i][j];
        //printf("count = %d\n", count);

        for(j=0;j<(*returnSize);j++){
            if(count==table[j]){ 
                if(click(strs[i], ans[j][(*returnColumnSizes)[j]-1], length)) continue;
                //printf("click\n");
                ans[j][(*returnColumnSizes)[j]] = malloc(sizeof(char)*(length+1));
                for(k=0;k<length;k++) ans[j][(*returnColumnSizes)[j]][k] = strs[i][k];
                ans[j][(*returnColumnSizes)[j]][k]  = '\0';
                (*returnColumnSizes)[j]+=1;
                key = 1;
                break;
            }
        }

        if(key==1){
            key = 0;
            continue;
        }

        ans[*returnSize] = malloc(sizeof(char*)*strsSize);
        ans[*returnSize][0] = malloc(sizeof(char)*(length+1));
        table[*returnSize] = count;
        for(j=0;j<length;j++) ans[*returnSize][0][j] = strs[i][j];
        ans[*returnSize][0][j]  = '\0';
        (*returnColumnSizes)[*returnSize] = 1;
        (*returnSize)++;
    }

    //printf("(*returnColumnSizes)[j] = %d, (*returnSize) = %d\n", (*returnColumnSizes)[j], (*returnSize));
   
    return ans;
}

























/*
失敗的版本

原本想用計算ASCII數去處理，但失敗了，會出現總和相等的狀況。

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #define SIZE 100
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char*** ans = malloc(sizeof(char**)*SIZE);
    ans[0] = malloc(sizeof(char*)*SIZE);
    ans[0][0] = malloc(sizeof(char)*SIZE);
    *returnColumnSizes = calloc(sizeof(int),SIZE);
    *returnSize = 0;
    int* table = malloc(sizeof(int)*strsSize);
    int i,j,k,length,count=0,key=0;

    for(i=0;i<strsSize;i++){
        count = 0;
        length = strlen(strs[i]);
        for(j=0;j<length;j++) count+=(int)strs[i][j];
        printf("count = %d\n", count);

        for(j=0;j<(*returnSize);j++){
            if(count==table[j]){ 
                //printf("click\n");
                ans[j][(*returnColumnSizes)[j]] = malloc(sizeof(char)*(length+1));
                for(k=0;k<length;k++) ans[j][(*returnColumnSizes)[j]][k] = strs[i][k];
                ans[j][(*returnColumnSizes)[j]][k]  = '\0';
                (*returnColumnSizes)[j]+=1;
                key = 1;
                break;
            }
        }

        if(key==1){
            key = 0;
            continue;
        }

        ans[*returnSize] = malloc(sizeof(char*)*strsSize);
        ans[*returnSize][0] = malloc(sizeof(char)*(length+1));
        table[*returnSize] = count;
        for(j=0;j<length;j++) ans[*returnSize][0][j] = strs[i][j];
        ans[*returnSize][0][j]  = '\0';
        (*returnColumnSizes)[*returnSize] = 1;
        (*returnSize)++;
    }

    //printf("(*returnColumnSizes)[j] = %d, (*returnSize) = %d\n", (*returnColumnSizes)[j], (*returnSize));
   
    return ans;
}