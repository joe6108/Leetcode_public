/*
 * 結果
 * Runtime : 103ms Beats 90.91%of users with C
 * Memory  : 22.09MB Beats 24.24%of users with C
 */
/*
 * 解題思路
 * 這題是來自: https://medium.com/@shouchungchang/leetcode-164-maximum-gap-3a181b8cbf01
 * 必須大概懂鴿籠原理以及桶子排列的概念。
 * 比較核心的思考方式就是我們必須建立桶子，每個桶子都是一個範圍，所以我們的數字有可能會因為劃分到
 * 同一個桶子而被覆蓋，但我們的重點是找出連續數值之間的最大間距，所以我們要找出的是相鄰桶子之間的
 * 間距是正確的，所以我們必須使用桶子排列做出兩個陣列，分別為Max和Min陣列，確保這兩個陣列的每個數
 * 都會是劃分到桶子中的數值中的最接近最大，最小範圍的數字。
 * 假設說我有一個桶子的範圍是1~4，而我分別放入1~4進去。
 * 那我的最大陣列的這個桶子中的數字，就是最接近4，也就是4的數值進去，1~3會被覆蓋。
 * 同理，最小陣列的數字就會是1。
 * 更進一步的來說，假設我們兩個桶子分別是1~4以及5~8兩個範圍的桶子
 * 那我現在放入2,4,5,6,8進去，那我的桶子分別會長成
 * MAX桶子 : [4,8]
 * MIN桶子 : [1,5] 
 * 那我們可以看出一個很重要的東西，那就是當我取MIN的5出來時，那我只要從相鄰的MAX的前一個值4。
 * 相減就是我們相鄰的最大間距了，但這個桶子的範圍是錯誤的，換一個例子，並用鴿籠原理解決。
 * 那我現在放入8,6,2,1,31進去 (假設排列好 1, 2, 6, 8, 31)
 * (31 - 1) / 4 = 7(範圍) , 總共為 (31 - 1) / 7 + 1 = 5
 * 將每個值扣掉最小(1)，並除上範圍，放入相應位置，例如 (8 - 1) / 7 = 1
 * MAX桶子 : 6 8 X X 31
 * MIN桶子 : 1 8 X X 31 (X為不存在)
 * 那我們就可以取出所有的間距，分別為8-6, 31-8，得到最大間距為23了，可以看出兩個桶子之間絕對是連續數值的
 * 最大間距。 
 * 
 */

int maximumGap(int* nums, int numsSize) {
    if(numsSize==1) return 0;
    // 桶子排列法
    int Max_num = INT_MIN, Min_num = INT_MAX;
    for(int i=0;i<numsSize;i++){
        if(nums[i] > Max_num) Max_num = nums[i];
        if(nums[i] < Min_num) Min_num = nums[i];
    }
    if(Max_num - Min_num == 0) return 0;
    // 桶子的大小跟數量
    int Buffer_size = (Max_num - Min_num) / (numsSize - 1) > 0 ? (Max_num - Min_num) / (numsSize - 1) : 1;
    int Buffer_count = (Max_num - Min_num) / Buffer_size + 1;
    // 設置兩個排列好的最大及最小排列
    int* Max_sort = malloc(sizeof(int)*Buffer_count);
    int* Min_sort = malloc(sizeof(int)*Buffer_count);
    // 初始化
    for(int i=0;i<Buffer_count;i++){
        Max_sort[i] = INT_MIN;
        Min_sort[i] = INT_MAX;
    }
    // 將數值放入桶子陣列做排序
    for(int i=0;i<numsSize;i++){
        int index = (nums[i] - Min_num) / Buffer_size;
        Max_sort[index] = nums[i] > Max_sort[index] ? nums[i] : Max_sort[index];
        Min_sort[index] = nums[i] < Min_sort[index] ? nums[i] : Min_sort[index];
        //printf("index = %d, nums[i] = %d\n", index, nums[i]);
    }
    int ans = 0;
    int i = 0, j = 0;
    while(i < Buffer_count){
        j = i + 1;
        while(j < Buffer_count && Min_sort[j]==INT_MAX){
            j++;
        }
        if(j == Buffer_count) break;
        if( Min_sort[j] - Max_sort[i] > ans) ans = Min_sort[j] - Max_sort[i];
        i = j;
    }
    free(Max_sort);
    free(Min_sort);
    return ans;
} 