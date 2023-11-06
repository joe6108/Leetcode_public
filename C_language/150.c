/*
 * 結果
 * Runtime : 5 ms Beats 71.14%of users with C
 * Memory  : 9.24MB Beats 6.50%of users with C
 */
/*
 * 解題思路
 * 因為題目的運作流程，就是每次在讀取到運算子的時候，對最靠近運算子(左側)的兩數做運算，所以我們第一個
 * 可以想到的就是stack，只要將所有數字都先放入stack裡面，當遇到運算子時，就能夠簡單的找出最近的兩個數
 * ，並對這兩個數做運算，運算結束之後，再將得出的結果放回stack，等待下次要使用的時候再取出來就好了。
 * 總結就是要處理順序的問題而已。
 * 
 */

#define SIZE 10000
struct stack{
    int A[SIZE];
    int top;
};

int empty(struct stack* s){
    return (s->top) == -1;
}

int full(struct stack* s){
    return (s->top)==(SIZE - 1);
}

void push(struct stack* s, int value){
    if(full(s)){
        printf("space already fulled\n");
        exit(1);
    }
    s->A[++(s->top)] = value;
}

int pop(struct stack* s){
    if(empty(s)){
        printf("space already emptyed\n");
        exit(2);
    }
    return s->A[(s->top)--];
}

int evalRPN(char** tokens, int tokensSize) {
    struct stack* s = malloc(sizeof(struct stack));
    int sum = 0, value = 0;
    for(int i=0 ; i<SIZE ; i++) s->A[i] = 0;
    s->top = -1;
    for(int i=0 ; i<tokensSize ; i++){
        int temp = tokens[i][0] - '0';
        if(temp >= 0 && temp <= 9){ //代表是正數
            value = atoi(tokens[i]);
            //printf("get %d\n", value);
            push(s, value);
        }else if(tokens[i][0]=='-' && tokens[i][1]!='\0'){ //負數
            value = atoi(tokens[i]);
            //printf("get %d\n", value);
            push(s, value);
        }else{ // 代表是加減乘除
            //printf("get %c\n", tokens[i][0]);
            int num1 = 0, num2 = 0;
            num2 = pop(s);
            num1 = pop(s);
            //printf("num1 = %d , num2 = %d\n ", num1, num2);
            if(tokens[i][0] == '+'){    
                num1+=num2;
            }else if(tokens[i][0] == '-'){
                num1-=num2;
            }else if(tokens[i][0] == '*'){
                num1*=num2;
            }else if(tokens[i][0] == '/'){
                num1/=num2;
            }else{
                printf("this is a error char = %c\n", tokens[i][0]);
                exit(3);
            }
            //printf("get a result = %d\n", num1);
            push(s, num1);
        }
    }
    while(!empty(s)) sum = pop(s);
    free(s);
    return sum;
}