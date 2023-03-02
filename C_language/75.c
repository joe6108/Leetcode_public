/*
 * 由於不太懂該題目想解決的問題核心，我就以不要以數字大小去做判斷為前提去解決問題。
 * 解決的方式是以統計的方式計算數量，再逐個更新，但這樣的方式在數量龐大的資料時會花太久，我認為該方式不太好，之後會參考他人的方式做改進。
 */


void sortColors(int* nums, int numsSize){
    int l = 0, r = numsSize-1, i;
    int sum[3] = {0};
    for(i=0;i<numsSize;i++){
        if(nums[i]==0) sum[0]++;
        if(nums[i]==1) sum[1]++;
        if(nums[i]==2) sum[2]++;
    }
    for(i=0;i<sum[0];i++) nums[i] = 0;
    for(i=sum[0];i<sum[0]+sum[1];i++) nums[i] = 1;
    for(i=sum[0]+sum[1];i<numsSize;i++) nums[i] = 2;
}