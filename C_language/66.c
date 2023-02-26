/*
 * 先將尾數加1之後，開始判斷是否需要進位，如果需要則將該位數設為零，將其上個位數的值加1，開始繼續判斷。
 * 需要注意的是當他進位的位置超過該數範圍，則需要特別新增一個新的陣列去除存新值。
 */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i,j;
    digits[digitsSize-1]+=1;
    for(i=digitsSize-1;i>-1;i--){
        if(digits[i]==10){
            digits[i] = 0;
            if(i==0){
                //create new array
                int* ans = malloc(sizeof(int)*(digitsSize+1));
                ans[0] = 1;
                for(j=0;j<digitsSize;j++) ans[j+1] = digits[j];
                *returnSize = digitsSize+1;
                return ans;
            }else{
                digits[i-1]+=1;
            }
        }else{
            break;
        }
    }
    *returnSize = digitsSize;
    return digits;
}