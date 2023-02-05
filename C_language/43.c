/*
by chatGPT

"Because it cannot be directly converted to an integer, a more convoluted approach must be taken by extracting each digit and converting them to integers and multiplying them individually.

Step 1: Determine if it's zero, if either number is zero then return "0".

Step 2: Determine the size of the answer first, it can be known from multiplication that the result of multiplication can be at most the sum of the number of digits of the two numbers plus one, and the remaining plus one needs to be determined.

Step 3: Perform multiplication of the two numbers, starting from the end, taking out the digits and multiplying them, if carrying, the value will be directly placed in the next digit.

Step 4: Determine the final end position, this refers to determining whether the remaining plus one in step 2 needs to be added.

Step 5: Finally, reverse the array, and the answer is obtained."

-----------------------------

因為不能直接轉成整數，所以得用取出每個位數，並分別轉成整數相乘的較迂迴的做法。

step1 : 判斷是否為零，如果任一數為0的話則直接回傳"0"

step2 : 先決定答案的大小，從乘法可以得知相乘的結果最多為兩者的位數相加再加1，剩餘的加1則是需要判斷。

step3 : 進行兩者的相乘，分別從最尾部開始取出位數並且相乘，如果進位的話則將值直接放入下個位子。

step4 : 接著決定最後的結尾位置，這邊指的就是決定step2剩下的加1是否需要。

step5 : 最後將陣列倒過來即是答案了。
*/


// Revise...

char * multiply(char * num1, char * num2){
    if(num1[0]=='0' || num2[0]=='0') return "0";
    int lengh_1 = strlen(num1);
    int lengh_2 = strlen(num2);
    int i = 0, j = 0, pos = 0, count = 0;
    char* ans = malloc(sizeof(char)*(lengh_1+lengh_2+1));
    memset(ans, '0', lengh_1+lengh_2+1);
    for(i = lengh_1-1 ; i > -1 ; i--){
        pos = (lengh_1-1)-i;
        for(j = lengh_2-1 ; j > -1 ; j--){
            count = (num1[i] - '0') * (num2[j] - '0') + (ans[pos] - '0');
            if(count > 9) ans[pos+1] = ( (ans[pos+1] - '0') + count/10 ) + '0';
            ans[pos] = ( count%10 ) + '0';
            pos++;
        }
    }
    if(ans[pos]!='0') pos++;
    for(i=0;i<pos/2;i++){
        j=pos-1-i;
        char tp;
        tp = ans[i];
        ans[i] = ans[j];
        ans[j] = tp;
    }
    ans[pos] = '\0';
    return ans;
}



// before...












char * multiply(char * num1, char * num2){
    if(!num1[0] && !num2[0]) return 0;
    if(num1[0] == '0') return num1;
    if(num2[0] == '0') return num2;
    int lengh_1 = strlen(num1);
    int lengh_2 = strlen(num2);
    int i = 0, j = 0, space = 16, pos = 0, count = 0;
    char* ans = malloc(sizeof(char)*space);
    memset(ans, '0', space);
    char* temp;
    for(i = lengh_1-1 ; i > -1 ; i--){
        pos = (lengh_1-1)-i;
        for(j = lengh_2-1 ; j > -1 ; j--){
            if((pos+2)>=space){
                space*=2;
                ans[pos+1] = '\0';
                temp = malloc(sizeof(char)*space);
                memset(temp, '0', space);
                strcpy(temp, ans);
                free(ans);
                ans = temp;
                ans[pos+1] = '0';
            }
            printf("pos = %d\n", pos);

            count = (num1[i] - '0') * (num2[j] - '0') + (ans[pos] - '0');
            printf("count = %d\n", count);

            if(count > 9) ans[pos+1] = ( (ans[pos+1] - '0') + count/10 ) + '0';
            printf("ans[pos] = %d\n",  (ans[pos] - '0'));

            ans[pos] = ( count%10 ) + '0';
            printf("ans[pos] = %c\n", ans[pos]);

            pos++;
        }
    }
    for(i=pos;i<pos+3;i++){
        if((i+2)>=space){
            space*=2;
            ans[i+1] = '\0';
            temp = malloc(sizeof(char)*space);
            memset(temp, '0', space);
            strcpy(temp, ans);
            free(ans);
            ans = temp;
            ans[i+1] = '0';
        }
        if(ans[i]!='0') pos++;
    }
    for(i=0;i<pos/2;i++){
        j=pos-1-i;
        char tp;
        tp = ans[i];
        ans[i] = ans[j];
        ans[j] = tp;
    }
    ans[pos] = '\0';
    for(j=0;j<pos;j++) printf("%c ", ans[j]);
    printf("\n");
    return ans;
}