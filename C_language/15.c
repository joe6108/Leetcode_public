/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MALLOC_UNIT 20000
static int compare(void *a, void *b)
{
    return *(int *) a - *(int *) b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int count = MALLOC_UNIT;
    int **ret = malloc(sizeof(int *) * count);
    *returnColumnSizes = malloc(sizeof(int) * count);
    if(numsSize<3){
        printf("ans is empty");
        return 0;
    }
    int sum,i,j,k=numsSize-1,pos=0,p,key;
    for(i=0;i<numsSize-2;i++){
        j=i+1;
        k=numsSize-1;
        while(j<k && k>i){
            sum = nums[i] + nums[j] + nums[k];
            if(sum>0){
                while(j<k){
                    if(nums[k]!=nums[k-1]){
                        break;
                    }
                    k--;
                }
                if(j<k) k--;
            }else if(sum<0){
                while(j<k){
                    if(nums[j]!=nums[j+1]){
                        break;
                    }
                    j++;
                }
                if(j<k) j++;
            }else{
                if(pos!=0){
                    for(p=pos-1;p>=0;p--){
                        if(ret[p][0]!=nums[i]) break;
                        if(ret[p][1]==nums[j]&&ret[p][2]==nums[k]){
                            key = 1;
                            break;
                        }
                    }
                }
                if(key==1){
                    key=0;
                    while(j<k){
                        if(nums[j]!=nums[j+1]){
                            break;
                        }
                        j++;
                    }
                    while(j<k){
                        if(nums[k]!=nums[k-1]){
                            break;
                        }
                        k--;
                    }
                    if(j<k) j++;
                    if(j<k) k--;
                }else{
                    if(pos>3000) printf("%d, %d, %d, %d\n",  nums[i],  nums[j],  nums[k], sum);
                    ret[pos] = malloc(sizeof(int) * 3);
                    (*returnColumnSizes)[pos] = 3;
                    ret[pos][0] = nums[i];
                    ret[pos][1] = nums[j];
                    ret[pos][2] = nums[k];
                    pos++;
                    while(j<k){
                        if(nums[j]!=nums[j+1]){
                            break;
                        }
                        j++;
                    }
                    while(j<k){
                        if(nums[k]!=nums[k-1]){
                            break;
                        }
                        k--;
                    }
                    if(j<k) j++;
                    if(j<k) k--;
                }
            }
        }
    }
    
    *returnSize = pos;
    return ret;
}