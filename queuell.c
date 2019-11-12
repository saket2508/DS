#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
typedef struct node NODE;
NODE*front,*rear;
void enqueue(int x){
    NODE*temp = (NODE*)malloc(sizeof(NODE));
    temp->link = NULL;
    temp->data = x;
    if(rear==NULL)
        rear = front = temp;
    else{
        front->link = temp;
        front = temp;
    }
}
int dequeue(){
    if(rear==front->link || rear==NULL){
         return -1;
    }
    NODE*ptr = rear;
    ptr = ptr->link;
    int res = rear->data;
    free(rear);
    rear = ptr;
    return res;
}

int main(){
    enqueue(3);
    enqueue(4);
    enqueue(56);
    printf("%d",dequeue());
    printf("%d",dequeue());
    printf("%d",dequeue());
    return 0;
}