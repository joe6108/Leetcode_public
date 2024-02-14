/*
 * 結果
 * Runtime : 0ms Beats 100.00%of users with C
 * Memory  : 6.44MB Beats 44.09%of users with C
 */
/*
 * 解題思路
 * 透過多個陣列作為轉換順序，依次轉換之後再做比較，有不同就代表是不同構。
 */

bool isIsomorphic(char* s, char* t) {
    int pos = 0, pos_max = 0, step = 1, step2 = 1;
    pos_max = strlen(s);
    int s_array[300] = {0}, t_array[300] = {0};
    int* s_r = calloc(pos_max, sizeof(int));
    int* t_r = calloc(pos_max, sizeof(int));
    while(pos < pos_max){
        //printf("s_array = %c, %d\n", s[pos], t[pos]);
        if(s_array[s[pos] - 0] == 0){
            s_array[s[pos] - 0] = step;
            s_r[pos] = step;
            step++;
        }else{
            s_r[pos] =  s_array[s[pos] - 0];
        }
        //printf("t_array = %c, %d\n", t[pos], t[pos]);
        if(t_array[t[pos] - 0] == 0){
            t_array[t[pos] - 0] = step2;
            t_r[pos] = step2;
            step2++;
        }else{
            t_r[pos] =  t_array[t[pos] - 0];
        }
        if(s_r[pos] != t_r[pos]){
            free(s_r);
            free(t_r);
            return false;
        }
        pos++;
    }
    free(s_r);
    free(t_r);
    return true;
}