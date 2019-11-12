#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue{
    int rear,front;
    int arr[MAX];
};
typedef struct queue QUEUE;
int Full(QUEUE*q){
    if(q->rear==q->front-1 || (q->rear==MAX-1 && q->front==0)){
        return 1;
    }
    return 0;
}
int Empty(QUEUE*q){
    if(q->rear==-1){
        return 1;
    }
    return 0;
}
void enqueue(QUEUE*q,int x){
    if(Full(q)){
        return ;
    }
    else if(q->rear==-1){
        q->rear = q->front = 0;
        q->arr[q->rear] = x;
    }
    else if(q->rear==MAX-1 && q->front!=0){
        q->rear = 0;
        q->arr[q->rear] = x;
    }
    else{
        q->rear++;
        q->arr[q->rear] = x;
    }
}
int dequeue(QUEUE*q){
    if(Empty(q)){
        return -1;
    }
    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    if(q->front==q->rear){
        q->front = q->rear = -1;
    }
    else if(q->front==MAX-1){
        q->front = 0;
    }
    else{
        q->front++;
    }
    return data;
}
int main(){
    QUEUE*q = (QUEUE*)malloc(sizeof(QUEUE));
    q->rear=-1;
    q->front=-1;
    enqueue(q,15);
    enqueue(q,25);
    enqueue(q,30);
    printf("%d\t",dequeue(q));
    enqueue(q,40);
    printf("%d\t",dequeue(q));
    printf("%d\t",dequeue(q));
    printf("%d",dequeue(q));
    free(q);
    return 0;
}