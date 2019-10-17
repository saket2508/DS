#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
typedef struct node NODE;
NODE* top;

void push(int data){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(!temp){
        printf("Stack Overflow\n");
        return ;
    }
    temp->info = data;
    temp->next = top;
    top = temp;
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int pop(){
    NODE*temp;
    if(isEmpty()){
        printf("Underflow Condition\n");
        return -1;
    }
    temp = top;
    int data = temp->info;
    top = top->next;
    //top wil now point to the previous node
    temp->next = NULL;
    free(temp);
    return data;
}

int main(){
    push(1);
    push(2);
    printf("%d",pop());
    return 0;
}