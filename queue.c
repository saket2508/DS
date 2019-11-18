#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct Queue{
    int rear,front;
    int arr[MAX];
};
typedef struct Queue QUEUE;
int isFull(QUEUE*q){
    if(q->front==0 && q->rear==MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(QUEUE*q){
    if(q->rear == q->front +1 || q->rear == -1){
        return 1;
    }
    return 0;
}
void Enqueue(QUEUE*q,int x){
    if(isFull(q)){
        return ;
    }
    else{
        if(q->rear == -1){
            q->rear++;
        }
        q->front++;
        q->arr[q->front] = x;
    }
}

int Dequeue(QUEUE*q){
    int item;
    if(isEmpty(q)){
        return -1;
    }
    else{
        item = q->arr[q->rear];
        q->rear++;
    }
    return item;
}

int top(QUEUE*q){
    int top = q->arr[q->front];
    return top;
}

int rear(QUEUE*q){
    int rear = q->arr[q->rear];
    return rear;
}

int main(){
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    q->rear = -1;
    q->front = -1;
    Enqueue(q,1);
    Enqueue(q,2);
    Enqueue(q,56);
    printf("%d\n",Dequeue(q));
    printf("%d\n",Dequeue(q));
    printf("%d",Dequeue(q));
    free(q);
    return 0;
}

