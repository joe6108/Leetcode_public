/*
 *  我使用的方式是參照網路上的別人找到的規律來做的，來自於: https://home.gamer.com.tw/artwork.php?sn=5282055
 *  由於我沒接觸過這類存在，所以就只參考她的方式，然後自己實作，就完成了。 
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int i,j,count = pow(2,n),sum = 0;
    *returnSize = count;
    char num[n];
    memset(num,'0',sizeof(char)*n);
    //printf("count = %d\n", count);
    int* ans = malloc(sizeof(int)*count);
    ans[0] = 0;
    for(i=1;i<count;i++){
        sum = 0;
        if(i%2==0){
            for(j=n-1;j>-1;j--){
                if(num[j]=='1'){
                    num[j-1] = (1 - (num[j-1] - '0') + '0');
                    break;
                }
            }
            for(j=0;j<n;j++){
                sum+=(num[n-j-1] - '0') * pow(2,j);
            }
            ans[i] = sum;
        }else{
            num[n-1] = (1 - (num[n-1] - '0') + '0');
            for(j=0;j<n;j++){
                sum+=(num[n-j-1] - '0') * pow(2,j);
            }
            ans[i] = sum; 
        }
    }
    return ans;
}