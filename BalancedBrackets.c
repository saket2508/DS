#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int arr[1000];
};
typedef struct stack STACK;
int isEmpty(STACK*s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(STACK*s){
    if(s->top==999){
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
}
int pop(STACK*s){
    if(isEmpty(s)){
        return -1;
    }
    int x = s->arr[s->top];
    s->top--;
    return x;
}
int top(STACK*s){
    int x = s->arr[s->top];
    return x;
}
int isOpeningBracket(char token){
    if(token == '(' || token == '[' || token == '{'){
        return 1;
    }
    return 0;
}
int isClosingBracket(char token){
    if(token == ')' || token == '}' || token == ']'){
        return 1;
    }
    return 0;
}
char PairingBracket(char token){
    char x;
    switch(token){
        case ')':
            x = '(';
            break;
        case ']':
            x = '[';
            break;
        case '}':
            x = '{';
            break;
        default:
            x = 0;
            break;
    }
    return x;

}
void isBalanced(char exp[]){
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    int i=0;
    while(exp[i] != '\0'){
        char token = exp[i];
        if(isOpeningBracket(token)){
            push(s,token);
        }
        else if(isClosingBracket(token)){
            if(top(s) == PairingBracket(token)){
                pop(s);
            }
            else{
                printf("NOT BALANCED");
                return ;
            }
        }
        else{
            printf("INVALID STRING EXPRESSION");
            return ;
        }
        i++;
    }
    if(isEmpty(s)){
        printf("BALANCED");
        return ;
    }
    else{
        printf("NOT BALANCED");
        return ;
    }

}

int main(){
    int T;
    scanf("%d",&T);
    char exp[30];
    for(int i=0;i<T;i++){
        scanf("%s",exp);
        isBalanced(exp);
    }
    return 0;
}