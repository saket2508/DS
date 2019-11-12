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
    temp->data = x;
    if(front==NULL){
        front = temp;
    }
    else{
        rear->link = temp;
    }
    temp->link = front;
    rear = temp;
}
int dequeue(){
   if(front==NULL){
       return -1;
   }
   int val;
   if(rear==front){
       val = front->data;
       free(front);
       front = rear = NULL;

   }
   else{
       NODE*temp = front;
       temp = temp->link;
       val = front->data;
       free(front);
       front = temp;
       rear->link = front;
   }
   return val;
}
void main(){
    enqueue(15);
    enqueue(25);
    enqueue(30);
    printf("%d\t",dequeue());
    enqueue(40);
    printf("%d\t",dequeue());
    printf("%d\t",dequeue());
    printf("%d",dequeue());
}

