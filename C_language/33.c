/*
Divide thinking into two, both cases are divided at index3, one is if the target is positive, for example:
1,2,3,4,5 => 4,5,1,2,3
Step1: If target > end character (3), it means it will be after 3, but this is the cut off point, so start searching from index0, otherwise search from the end backwards.
Step2: Assuming search from index0, as the range is unknown, the range will be assumed to be the total length (numsSize - 1), if the value of the found index is greater than the target, it means it does not exist, similarly for the end character.

If negative, the situation is opposite.
*/ 
// english translation by charGPT 


/*
將思考分為兩種，兩種情況同樣在inedex3的時候被切分，一種是如果目標為正的情況，例如:
1,2,3,4,5 => 4,5,1,2,3
step1 : 如果target > 字尾(3)，代表他會在3的後面，但這裡是截斷處，所以得從index0開始找，反之從字尾開始往前找。
setp2 : 假設從index0開始找，因為不知道範圍多大，所以範圍會先假設為總長(numsSize - 1)，如果找到的index的數值會大於我們target，代表他並不存在，
反之字尾亦同。

如果為負則情況相反。
*/




int search(int* nums, int numsSize, int target){
    int t = numsSize - 1;
    if(nums[t]==target || numsSize==0) return t;
    if(target >= 0){
        if(nums[t] < target){
            t = 0;
            for(t;t<numsSize;t++){
                if(nums[t]==target) return t;
                if(nums[t] > target) break;
            }
        }else{
            t--;
            for(t;t>-1;t--){
                if(nums[t]==target) return t;
                if(nums[t] < target) break;
            }
        }
    
    }else{
        if(nums[t] > target){
            t = 0;
            for(t;t<numsSize;t++){
                if(nums[t]==target) return t;
                if(nums[t] > target) break;
            }
        }else{
            t--;
            for(t;t>-1;t--){
                if(nums[t]==target) return t;
                if(nums[t] < target) break;
            }
        }
    }

    return -1;
}