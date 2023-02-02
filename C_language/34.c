/*
"Because it is incremental, I use the method of searching one by one, because I believe that as long as the first one is found, then we can search one by one.
Given: In the search process, because it is an increasing sequence, we can know that as long as the number represented by the found position is greater than our target, it means the target is not in the array. For example:
1,2,3,6,7, target = 4, when we find 6, we can know that the number is not in the array. (---> if(nums[pos]>target) break; <---)
Step 1: After finding the target, first check if it is the primary target, if so, assign the value first. Since it may also be the first and the last, the second value is also assigned.
Step 2: After finding the second target, first check if its position after is out of range, if so, it means it must be the last found value.
Step 3: If not, it means it may not be the last one, at this time we need to check if it is equal to the target value with the next one, if it is different, it means it is the last one, otherwise continue searching."
-- English translation by charGPT --
因為他是遞增，所以我使用逐個搜尋的方式，因為我認為只要找到第一個之後，再逐個搜尋即可。
前提: 在找尋的過程中，因為他是遞增數列，所以我們可以知道只要找到的位置代表的數字大於我們的目標，就代表目標不在陣列中，例如:
1,2,3,6,7，target = 4 ， 當我們在找到6的時候，就可以知道這個數字不在陣列中了。(--->  if(nums[pos]>target) break;   <---)
step1 : 當找到目標後，先確認是否為首要目標，是的話就先賦予值，由於他也可能既是第一個也是最後一個，所以第二個值也先賦予。
step2 : 找到第二個目標後，要先檢查其後的位置是否超出範圍，是的話就代表他必定是最後找到的值。
step3 : 如果不是，則代表它可能不是最後一個，這時就要檢查他和後一個值是否等於目標值，不同的話代表他為最後一個，反之則繼續搜尋。
*/


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int pos;
    int* ans = (int*)malloc(sizeof(int)*2);
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;
    for(pos=0;pos<numsSize;pos++){
        if(nums[pos]>target) break;
        if(nums[pos]==target){
            if(ans[0]==-1){
                ans[0] = pos;
                ans[1] = pos;
            }else{
                if(pos+1!=numsSize){
                    if(nums[pos]!=nums[pos+1]){
                        ans[1] = pos;
                    }
                }else{
                    ans[1] = pos;
                }
            }
        }
    }
    return ans;
}