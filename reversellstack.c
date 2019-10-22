#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*link;
};
typedef struct node NODE;
struct stack{
    int top;
    NODE*arr[100];
};
typedef struct stack STACK;
NODE*createList(){
    NODE*head= NULL,*temp,*newnode;
    int nnodes,nvalue;
    scanf("%d",&nnodes);
    int n=0;
    while(n<nnodes){
        newnode = (NODE*)malloc(sizeof(NODE));
        scanf("%d",&nvalue);
        newnode->info = nvalue;
        newnode->link = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            temp->link = newnode;
        }
        temp = newnode;
        n++;
    }
    return head;
}
int isFull(STACK*s){
    if(s->top>=99){
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
void push(STACK*s,NODE*n){
    if(isFull(s)){
        return ;
    }
    s->top++;
    s->arr[s->top] = n;
}
NODE* pop(STACK*s){
    if(isEmpty(s)){
        return NULL;
    }
    NODE*n = s->arr[s->top];
    s->top--;
    return n;
}
NODE*reverseList(NODE*head){
    if(head==NULL){
        printf("null");
        return NULL;
    }
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    NODE*ptr;
    ptr = head;
    while(ptr!=NULL){
        push(s,ptr);
        ptr = ptr->link;
    }
    head = pop(s);
    ptr = head;
    while(!isEmpty(s)){
        ptr->link = pop(s);
        ptr = ptr->link;
    }
    ptr->link = NULL;
    return head;
}
void displayList(NODE*head){
    if(head==NULL){
        printf("not able to display list");
        return ;
    }
    while(head!=NULL){
        printf("%d\t",head->info);
        head = head->link;
    }
}
void main(){
    NODE*head;
    head = createList();
    head = reverseList(head);
    displayList(head);
}