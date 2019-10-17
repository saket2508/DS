#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stack{
    int top;
    int arr[MAX];
};
typedef struct stack STACK;

int isFull(STACK*s){
    if(s->top >= MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(STACK*s){
    if(s->top<=-1){
        return 1;
    }
    return 0;
}
void push(int x,STACK* s){
    if(isFull(s)){
        printf("Overflow condition\n");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top] = x;
    }
    return ;
}
int pop(STACK*s){
    int res;
    if(isEmpty(s)){
        printf("Underflow Condition\n");
        return -1;
    }
    else{
        res = s->arr[s->top];
        s->top--;
    }
    return res;
}
int top(STACK*s){
    if(s->top <= -1){
        return -1;
    }
    int res = s->arr[s->top];
    return res;
}
int main(){
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    push(10,s);
    push(28,s);
    printf("%d",pop(s));
}