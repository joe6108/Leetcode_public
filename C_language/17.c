/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    //0-2, 1-3, 2-4, 3-5, 4-6, 5-7, 6-8, 7-9
    char value[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int count[4] = {0};
    int i,j,k;
    for(i=0, j=0;i<strlen(digits);i++){
        //printf("%d ", digits[i] - '0');
        if( digits[i] - '0' < 10 &&  digits[i] - '0' > 1) count[j++] = digits[i] - '0' - 2;
    }
    char** ans = NULL;
    int c_count = pow(4, j+1);
    ans = (char**)malloc(c_count * sizeof(char*));
    for(int h=0;h<c_count;h++){
        ans[h] = (char*)malloc(sizeof(char)*5);
    }

    printf("\n%d\n", strlen(value[count[1]]));



    int pos=0;
    int f1,f2,f3,f4;
    if(j>0){
        for(f1=0;f1<strlen(value[count[0]]);f1++){
            if(j>1){
                for(f2=0;f2<strlen(value[count[1]]);f2++){
                    if(j>2){
                        for(f3=0;f3<strlen(value[count[2]]);f3++){
                            if(j>3){
                                for(f4=0;f4<strlen(value[count[3]]);f4++){
                                    //ans[pos] = (char*)malloc(sizeof(char)*5);
                                    ans[pos][0] = value[count[0]][f1];
                                    ans[pos][1] = value[count[1]][f2];
                                    ans[pos][2] = value[count[2]][f3];
                                    ans[pos][3] = value[count[3]][f4]; 
                                    ans[pos][4] = '\0';
                                    pos++;
                                }
                            }else{
                                //ans[pos] = (char*)malloc(sizeof(char)*4);
                                ans[pos][0] = value[count[0]][f1];
                                ans[pos][1] = value[count[1]][f2];
                                ans[pos][2] = value[count[2]][f3];
                                ans[pos][3] = '\0';
                                pos++;
                            }
                        }
                    }else{
                        //ans[pos] = (char*)malloc(sizeof(char)*3);
                        ans[pos][0] = value[count[0]][f1];
                        ans[pos][1] = value[count[1]][f2];
                        ans[pos][2] = '\0';
                        pos++;
                    }
                }
            }else{
                //ans[pos] = (char*)malloc(sizeof(char)*2);
                ans[pos][0] = value[count[0]][f1];
                ans[pos][1] = '\0';
                pos++;
            }
        }
    }
    printf("pos = %d\n", pos);
    for(int m=0;m<pos;m++){
        for(int n=0;n<5;n++){
            printf("%c", ans[m][n]);
        }
    }

    printf("%d", ans[1][0]==NULL);


    *returnSize = pos;
    return ans;
    
    
}