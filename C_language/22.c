//this is a backtrace function.
void repeat_lookup(int val,char*** ans_space,char* get_ans,int left,int right,int n,int* returnSize,int* max){
    if(val==(2*n)){ // if this loop limit arrive max.
        get_ans[2*n] = '\0'; // because it is a string.
        if(*returnSize == (*max)){ // this memory need to add.
            (*max) = (*max)*4; 
            char** ptr = realloc((*ans_space), (*max)*sizeof(char*)); //update
            if(!ptr){
                printf("error");
                exit(1);
            } 
            (*ans_space) = ptr;
        }
        (*ans_space)[*returnSize] = (char*)malloc((2*n+1)*sizeof(char)); //write a new answer.
        strcpy((*ans_space)[*returnSize],get_ans);
        *returnSize+=1;     
    }
    // if '(' < n(max_quality).
    if(left<n){ 
        get_ans[val] = '(';
        repeat_lookup(val+1,ans_space,get_ans,left+1,right,n,returnSize,max);
    } 
    // because up's decide is occur, so it will enter next decide(if).
    if(left>right){
        get_ans[val] = ')';
        repeat_lookup(val+1,ans_space,get_ans,left,right+1,n,returnSize,max);
    }
    // if two decide(if) can't enter, then it will dumped.
}

char ** generateParenthesis(int n, int* returnSize){
    *returnSize = 0;
    int max=2;
    char** ans_space = (char**)malloc(max*sizeof(char*));
    char* get_ans = (char*)malloc((2*n+1)*sizeof(char)); // store correct answer.
    //(loop's limit, main space (two dimension), correct answer, quantity about '(', quantity about ')', limit of ')' and '(', answer's length, limit memory max)
    repeat_lookup(0,&ans_space,get_ans,0,0,n,returnSize,&max);
    return ans_space;
    
}