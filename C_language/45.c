// 這是一個題意有問題的題目
// this is a not good's problem
// 無法完成[2,3,0,1,1,5]。

int jump(int* nums, int numsSize){
    int i,new_lenth=0,now_length=0,step=0;
    for(i=0;i<numsSize-1;i++){
        now_length = now_length > (nums[i] + i) ? now_length : (nums[i] + i);
        if(i == new_lenth){
            new_lenth = now_length;
            step++;
        }
    }
    return step;
}











// before...

int search_loop(int* nums, int target, int level, int n, int step){
    //printf("level = %d, n = %d, step = %d, target = %d\n", level, n, step, (target - step));
    if(level == n && (target - step) <= 0){
        return 1;
    }else if(level < n){
        for(int i=1;i<=nums[step];i++){
            if(search_loop(nums, target, level+1, n, (i+step))) return 1;
        }
    }
    return 0;
}

int jump(int* nums, int numsSize){
    int target = numsSize - 1;
    int i,j;
    if(numsSize==1) return 0;
    for(i=1;i<numsSize;i++){
        for(j=1;j<=nums[0];j++){
            if(search_loop(nums, target, 1, i, j)) return i;
        }
    }

    return -1;
}