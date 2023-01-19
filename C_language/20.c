#define SIZE 10000
//Create a stack
struct stack
{   
    char A[SIZE];
    int top;
};

int empty(struct stack* s){
    return s->top==-1;
}
int full(struct stack* s){
    return s->top==SIZE-1;
}
void push(struct stack* s, char val){
    s->A[++s->top] = val;
}

char pop(struct stack* s){
    return s->A[s->top--];
}

bool isValid(char * s){
    struct stack* Stack_1 = NULL;
    Stack_1 = (struct stack*)calloc(1, sizeof(struct stack)); //allocation space
    Stack_1->top = -1; //init
    int pos = 0; //s's position
    char tmp; 
    while(s[pos]!='\0'){
        // decide full?
        if((s[pos]=='(')||(s[pos]=='{')||(s[pos]=='[')){
            if(full(Stack_1)){
                printf("full");
                return false;
            }
            push(Stack_1, s[pos]);
        }else{
            // decide empty?
            if(empty(Stack_1)) return false;
            tmp = pop(Stack_1);
            if(tmp=='(' && s[pos]!=')') return false;
            else if(tmp=='{' && s[pos]!='}') return false;
            else if(tmp=='[' && s[pos]!=']') return false;
        }
        pos++;
    }
    if(!empty(Stack_1)){
        free(Stack_1);
        return false;
    }else{
        free(Stack_1);
        return true;
    }
}