#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack{
    int top;
    int arr[MAX];
};
typedef struct stack STACK;
int isFull(STACK*s){
    if(s->top==MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(STACK*s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
void push(STACK*s,int x){
    if(isFull(s)){
        return ;
    }
    s->top++;
    s->arr[s->top] = x;
    return ;
}
int top(STACK*s){
    int x = s->arr[s->top];
    return x;
}
int pop(STACK*s){
    if(isEmpty(s)){
        return -1;
    }
    int x = s->arr[s->top];
    s->top--;
    return x;
}
int isOperator(char token){
    if(token == '+' || token == '-' || token == '/' || token == '*'){
        return 1;
    }
    return 0;
}
int isOperand(char token){
    if(token >= '1' &&  token <= '9'){
        return 1;
    }
    return 0;
}
int precedence(char token){
    switch(token){
        case '+':
            return 1;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
        case '/':
            return 2;
            break;
    }
}
int hasHigherPrecedence(char token,char op){
    if(precedence(token) <= precedence(op)){
        return 1;
    }
    return 0;
}
int performOp(char op,int op1,int op2){
    int res;
    switch(op){
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
int eval(char exp[]){
    STACK s1,s2;
    s1.top = s2.top = -1;
    int i=0;
    while(exp[i] != '\0'){
        char token = exp[i];
        if(isOperand(token)){
            token = token - 48;
            push(&s1,token);
        }
        else if(isOperator(token)){
            if(isEmpty(&s2) || !hasHigherPrecedence(token,top(&s2)) || top(&s2)=='('){
                push(&s2,token);
            }
            else{
                char op = pop(&s2);
                int op2 = pop(&s1);
                int op1 = pop(&s1);
                int res = performOp(op,op1,op2);
                push(&s1,res);
                push(&s2,token);
            }
        }
        else if(token == '('){
            push(&s2,token);
        }

        else{
            while(top(&s2) != '('){
                char op = pop(&s2);
                int op2 = pop(&s1);
                int op1 = pop(&s1);
                int res = performOp(op,op1,op2);
                push(&s1,res);
            }
            pop(&s2);
        }
        i++;
    }
    while(!isEmpty(&s2)){
        char op = pop(&s2);
        int op2 = pop(&s1);
        int op1 = pop(&s1);
        int res = performOp(op,op1,op2);
        push(&s1,res);
    }
    int res = pop(&s1);
    return res;
}
int main(){
    char exp[30];
    printf("Enter infix expression\n");
    scanf("%s",exp);
    printf("%d",eval(exp));
    return 0;
}