#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(STACK*s,char op){
    if(isFull(s)==1){
        printf("Overflow Condition\n");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top] = op;
    }
}

void pop(STACK*s){
    if(isEmpty(s)==1){
        printf("underflow condition");
        return ;
    }
    else{
        s->top--;
    }
}

int top(STACK*s){
    int res = s->arr[s->top];
    return res;
}

int isOperand(char token){
    if(token >= '0' && token <= '9'){
        return 1;
    }
    else if(token >= 'a' && token <= 'z'){
        return 1;
    }
    else if(token >= 'A' && token <= 'Z'){
        return 1;
    }
    return 0;
}

int isOperator(char token){
    if(token == '+' || token == '-' || token == '*' || token == '/'){
        return 1;
    }
   return 0;
}

int opPrecedence(char token){
    if(isOperator(token)){
        switch(token){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
    }
    else{
        return -1;
    }
}

int hasHigherPrecedence(char token,char op){
    if(opPrecedence(token) > opPrecedence(op)){
        return 1;
    }
    else{
        return 0;
    }
}

void infixTopostfix(char exp[]){
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    char res[30];
    int k = 0;
    int i = 0;
    while(exp[i] != '\0'){
        char token = exp[i];
        if(isOperand(token)==1){
            res[k++] = token;
        }
        else if(token == '('){
            push(s,token);
        }
        else if(token == ')'){
            while(top(s) != '('){
                char add = top(s);
                pop(s);
                res[k++] = add;
            }
            pop(s);
        }
        else if(isOperator(token)==1){
            if(hasHigherPrecedence(token,top(s)==1) || isEmpty(s)==1 || top(s)== '('){
                push(s,token);
            }
            else{
                while(opPrecedence(top(s)) >= opPrecedence(token)){
                    char op = top(s);
                    res[k++] = op;
                    pop(s);
                }
                push(s,token);
            }

        }
        else{
            continue;
        }
        i++;
    }
    while(isEmpty(s)!=1){
        char op = top(s);
        res[k++] = op;
        pop(s);
    }

    puts(res);
}

int main(){
    char exp[30];
    printf("Enter infix expression\n");
    gets(exp);
    infixTopostfix(exp);
    return 0;
}
