/*
 * 結果
 * Runtime : 0ms Beats 100.00%of users with C
 * Memory  : 6.51MB Beats 27.27%of users with C
 */
/*
 * 解題思路
 * 以.區別每個分段，並對每個分段做總和，只要出現了一個大小不均就會得出答案。
 * 
 */

int compareVersion(char* version1, char* version2) {
    int v1_len = strlen(version1), v2_len = strlen(version2), equla = 0, i = 0, j = 0;
    long long v1_result = 0, v2_result = 0, index = 0;
    while(version1[i]!='\0' || version2[j]!='\0'){
        //printf("i=%d, j=%d\n", i, j);
        v1_result = 0;
        v2_result = 0;
        while(version1[i]!='\0' && version1[i]!='.'){
            //printf("v1 = %d\n", version1[i]);
            v1_result = v1_result*10 + version1[i] - '0';
            i++;
        }
        while(version2[j]!='\0' && version2[j]!='.'){
            //printf("v2 = %d\n", version2[j]);
            v2_result = v2_result*10 + version2[j] - '0';
            j++;
        }
        if(v1_result < v2_result) return -1;
        if(v1_result > v2_result) return 1;
        if(version1[i]!='\0') i++;
        if(version2[j]!='\0') j++;
    }
    return 0;
}