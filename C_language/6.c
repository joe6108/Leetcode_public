

//2023/2/16
char * convert(char * s, int numRows){
    char* ans = malloc(sizeof(char)*1001);
    if(numRows==1) return s;
    int i,j,step,length,pos=0;
    int count = 0;
    length = strlen(s);
    //printf("length = %d, numRows = %d\n", length, numRows);
    step = (numRows-1)*2;
    for(i=0;i<numRows;i++){
        for(j=i;j<length;j+=step){
            if(i!=0 && i!=numRows-1){
                ans[pos++] = s[j];
                if((j+step-(2*i))<length)ans[pos++] = s[(j+step-(2*i))];
            }else{
                ans[pos++] = s[j];
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}



char * convert(char * s, int numRows){
    int length = strlen(s); 
    if(s[0] == '\0') return 0;
    if(numRows == 1) return s;
    if(length <= numRows){
        for(int i=0;i<length;i++){
            printf("\n%c", s[i]);
        }
        return s;
    }
    char *s_ans = (char *)calloc((length+1),sizeof(char));
    
    int pos = 0;
    int fixed_pos = (numRows - 1)*2;
    int count = 0;
    int count2 = 0;
    if(numRows!=2){
        for(int i=0;i<numRows;i++){
            if(i==0){
                count = i;
                while(count<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                }
            }else if (i >= 1 && i <= (numRows-2)){
                count = i;
                count2 = fixed_pos - i;
                while(count<=(length-1) && count2<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                    s_ans[pos] = s[count2];
                    pos++;
                    count2+=fixed_pos;
                }
                if(count<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                }
                if(count2<=(length-1)){
                    s_ans[pos] = s[count2];
                    pos++;
                    count2+=fixed_pos;
                }       
            }else{
                count = i;
                while(count<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                }
            }
            
        }
    }else{
        for(int i=0;i<numRows;i++){
            if(i==0){
                count = 0;
                while(count<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                }
            }else{
                count = 1;
                while(count<=(length-1)){
                    s_ans[pos] = s[count];
                    pos++;
                    count+=fixed_pos;
                }
            }
        }
    }
    return s_ans;
}   