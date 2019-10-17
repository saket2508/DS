#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct stack{
    int arr[MAX];
    int top;
};
typedef struct stack STACK;

int isFull(STACK*s){
    if(s->top >= MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(STACK*s){
    if(s->top <= -1){
        return 1;
    }
    return 0;
}

void push(STACK*s,int x){
    if(isFull(s)){
        printf("Overflow Condition\b");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top] = x;
    }
}

int top(STACK*s){
    if(isEmpty(s)){
        printf("Underflow Codition\n");
        return -1;
    }
    int res = s->arr[s->top];
    return res;
}

void pop(STACK*s){
     if(isEmpty(s)){
        printf("Underflow Codition\n");
        return ;
    }
    s->top--;
}

int isDigit(char c){
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return 1;
    }
    return 0;
}

int performOP(int op1,int op2,char token){
    int res;
    switch(token){
        case '+':
            res = op1+op2;
            break;
        case '-':
            res = op1-op2;
            break;
        case '/':
            res = op1/op2;
            break;
        case '*':
            res = op1*op2;
            break;
    }
    return res;
}

int postfixEvaluation(char exp[]){
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    int i = 0;
    while(exp[i] != '\0'){
        char token = exp[i];
        if(isDigit(token)){
            token = token - 48;
            push(s,token);
        }
        else if(isOperator(token)){
            int op2 = top(s);
            pop(s);
            int op1 = top(s);
            pop(s);
            int res = performOP(op1,op2,token);
            push(s,res);
        }
        i++;

    }
    int res = top(s);
    return res;
}

int main(){
    char exp[30];
    printf("Enter postfix exp\n");
    gets(exp);
    printf("%d",postfixEvaluation(exp));
    return 0;
}