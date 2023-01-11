#define SIZE 100
// Use heap to deal this problem
/*
I       1
V       5
X       10
L       50
C       100
D       500
M       1000
1 <= enter <= 3999
*/
struct stack {
    char A[SIZE];
    int top;
};

int empty(struct stack* s){
    return s->top == -1;
}

int full(struct stack* s){
    return s->top == SIZE - 1;
}

void push(struct stack* s, char sty){
    if(full(s)){
        printf("this stack is full");
        exit(1);
    }
    s->A[++s->top] = sty;
}

char pop(struct stack *s){
    if(empty(s)){
        printf("this stack is empty");
        exit(2);
    }
    return s->A[s->top--];
}

int max_len(int x){
    int length = 0;
    while(x/10!=0){
        length++;
        x/=10;
    }
    length++;
    return length;
}

char * intToRoman(int num){
    struct stack* s1 = NULL;
    s1 = (struct stack*)calloc(1, sizeof(struct stack));
    s1->top = -1;
    int i,j;
    int tmp = 0;
    char result[30];
    int length = max_len(num);
    printf("enter count = %d\n", num);
    printf("max length = %d\n", length);

    for(i=0;i<length;i++){
        printf("num = %d\n", num);
        tmp = num % 10;
        num/=10;
        tmp = tmp * pow(10, i);
        if(tmp > 0 && tmp < 10){
            if(tmp == 9){
                push(s1, 'X');
                push(s1, 'I');
            }else if(tmp == 4){
                push(s1, 'V');
                push(s1, 'I');
            }else{
                if(tmp >= 5){
                    tmp-=5;
                    for(j=0;j<tmp;j++){
                        push(s1, 'I');
                    }
                    push(s1, 'V');
                }else{
                    for(j=0;j<tmp;j++){
                        push(s1, 'I');
                    }
                }
            }
        }else if(tmp >= 10 && tmp < 100){
            if(tmp == 90){
                push(s1, 'C');
                push(s1, 'X');
            }else if(tmp == 40){
                push(s1, 'L');
                push(s1, 'X');
            }else{
                tmp/=10;
                if(tmp >= 5){
                    tmp-=5;
                    for(j=0;j<tmp;j++){
                        push(s1, 'X');
                    }
                    push(s1, 'L');
                }else{
                    for(j=0;j<tmp;j++){
                        push(s1, 'X');
                    }
                }
            }
        }else if(tmp >= 100 && tmp < 1000){
            if(tmp == 900){
                push(s1, 'M');
                push(s1, 'C');
            }else if(tmp == 400){
                push(s1, 'D');
                push(s1, 'C');
            }else{
                tmp/=100;
                if(tmp >= 5){
                    tmp-=5;
                    for(j=0;j<tmp;j++){
                        push(s1, 'C');
                    }
                    push(s1, 'D');
                }else{
                    for(j=0;j<tmp;j++){
                        push(s1, 'C');
                    }
                }
            }
        }else if(tmp >= 1000){
            tmp/=1000;
            for(j=0;j<tmp;j++){
                push(s1, 'M');
            }
        }else{
            continue;
        }
    }
    struct stack* s2 = NULL;
    s2 = (struct stack*)calloc(1, sizeof(struct stack));
    s2->top = -1;
    
    int pos = -1;
    while(!empty(s1)){
        push(s2, pop(s1));
    }
    free(s1);
    char* s = s2->A;
    return s;
}