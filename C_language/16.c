/*
依照距離去判斷接近答案與否。
*/

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    //sort
    qsort(nums,numsSize,sizeof(int),compare);
    //see sort array
    for(int p=0;p<numsSize;p++)
        printf("%d ",nums[p]);
    if(numsSize<3){printf("\nSize<3");return 0;}
    //ans=答案，i,j,k為相對的位置(第一位，第一位後一位，最後一位)，record=紀錄目標在扣掉i位的值後，j和k相加需要為多少，f=j,k位置的數值相加，d=距離，且d必須大於0
    int ans=nums[0]+nums[1]+nums[2],i=0,j,k,record,f,d=ans-target;
    if(d<0) d*=(-1);
    for(i;i<numsSize-2;i++){
        //目標-紀錄 測量
        record = target - nums[i];
        j=i+1;
        k=numsSize-1;
        while(j<k){
            f = nums[j]+nums[k];
            if(f==record){
                return target;
            }else if(f>record){
                if((f-record)<d){
                    ans = nums[i]+nums[j]+nums[k];
                    d = f-record;
                }
                k--;
            }else{
                if((record-f)<d){
                    ans = nums[i]+nums[j]+nums[k];
                    d = record-f;
                }
                j++;
            }
        }
    }
    return ans;
}