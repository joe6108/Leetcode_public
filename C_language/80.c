/*
 * 這題比較麻煩，我使用的方式是透過一組一組判斷(兩個為一組)是否重複的指標，舉個例子來說，當遇到 222 的時候，index = 0 時，他會和 index = 1 做判斷，
 * 代表前面的->22<-2 已經告訴了我們它已經有了重複的存在了，這邊使用flag去紀錄我已經得到了重複項，那麼接下來的2就能皆無視掉了。
 * 只要能弄懂這一點，剩下就簡單了，我在處理陣列的方式時，是透過替換掉當前index的下一個位置(index+1)來做陣列更替，也就是說每次執行for迴圈，
 * 我都會進行這個動作，無論我更新的數字是否是相同的，除了一個例外，那就是當我發現三個以上的重複項(flag=true)，按照這個方式，最後就能得到
 * 我們想要的答案了。
 * 
 * 備註: 下方兩個方法都能達成，上面是從當前位置的下一個開始更替，下面是從當前位置就開始更替，兩者的差別只有下面的方式要補上最後一個位數的值。 
 */



int removeDuplicates(int* nums, int numsSize){
    int head = 1, pos = 0;
    bool flag = false;
    for(pos=0;pos<numsSize-1;pos++){
        if(nums[pos] == nums[pos+1]){
            if(!flag){
                flag = true;
                nums[head++] = nums[pos+1];
            }
        }else{
            flag = false;
            nums[head++] = nums[pos+1];
        }
    }
    return head;
}




int removeDuplicates(int* nums, int numsSize){
    int head = 0, pos = 0;
    bool flag = false;
    for(pos=0;pos<numsSize-1;pos++){
        if(nums[pos] == nums[pos+1]){
            if(!flag){
                flag = true;
                nums[head++] = nums[pos];
            }
        }else{
            flag = false;
            nums[head++] = nums[pos];
        }
    }
    nums[head++] = nums[pos];
    return head;
}