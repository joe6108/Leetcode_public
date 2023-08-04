/*
 * 這個方式也適用於上一題，雖然這個作法是因為我看了前一題的人用的才搬到這題修改了一下，畢竟原本上一題的方式無法簡單的解決這題。
 *
 * 這題使用的方式是以陣列的方式儲存每個節點的開頭，從而得出下一個level有多少節點，而這個陣列的最大值之所以設定為1001其實我不太了解。
 * 而上述的方式舉個例子來說，就是 *returnSize的值代表了每個level有多少個節點，所以當*returnSize的值為1時，代表他在最上層，只有單個或沒有
 * 節點的狀況。
 * 
 * 接著，設置了兩個int變數 head 和 tail 分別代表指定取得的陣列位置，以環狀stack的取得方式有異曲同工之妙，也就tail代表了其最終陣列位置
 * head代表了開頭(取道哪裡)，舉實際例子來看，如果陣列為[0,1,2,3]，head = 0, tail = 4，如果tail - head != 0 時。
 * step1 : 取0 ， head+1 = 1
 * step2 : 取1 ， head+1 = 2
 * step3 : 取2 ， head+1 = 3
 * step4 : 取3 ， head+1 = 4
 * head會隨著取得數值而增加。
 * 而這題的方式也是如此，假設現在的二元樹長成下面那樣:
 *          2
 *         / \ 
 *        1   3
 * 陣列假設為s[3], 開頭初始 s[0] = 2 ， head = 0 , tail = 1。
 * step1 : 取得tail-head的所有數值，得到2這個節點，同時head++，但同時還要查看節點2是否還有左節點或右節點，head = 1 , tail = 1。
 * step2 : 如果2有左節點(1)，s[tail++] = 1 。 tail  = 2。
 * step2 : 如果2有右節點(3)，s[tail++] = 3 。 tail  = 3。
 * 那麼就又能繼續循環了，同時你還能透過 head - tail 知道下一個level有多少個node節點。
 * 
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(!root) return NULL;
    struct TreeNode* table[1001];
    int head = 0, tail = 0;
    table[tail++] = root;
    int** ans = malloc(sizeof(int*)*2001);
    (*returnColumnSizes) = malloc(sizeof(int)*2001);
    while( (tail - head) % 1001 > 0){
        int num = ( tail - head ) % 1001;
        (*returnColumnSizes)[*returnSize] = num;
        ans[*returnSize] = malloc(sizeof(int)*num);
        for(int i=0;i<num;i++){
            struct TreeNode* temp = table[head++ % 1001];
            if((*returnSize)%2) ans[*returnSize][num-i-1] = temp->val;
            else ans[*returnSize][i] = temp->val;
            if(temp->left) table[tail++ % 1001] = temp->left;
            if(temp->right) table[tail++ % 1001] = temp->right;
        }        
        (*returnSize)++;
    }
    return ans;
}