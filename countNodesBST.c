/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*left,*right;
};
typedef struct node NODE;
struct queue{
    int rear,front;
    NODE* arr[100];
};
typedef struct queue QUEUE;
int isEmpty(QUEUE*q){
    if(q->front==-1 || q->front==q->rear+1){
        return 1;
    }
    return 0;
}
void enqueue(QUEUE*q,NODE*n){
    if(q->front==-1){
        q->front++;
    }
    q->rear++;
    q->arr[q->rear] = n;
    return ;
}
NODE* dequeue(QUEUE*q){
    if(isEmpty(q)){
        return NULL;
    }
    NODE*n = q->arr[q->front];
    q->front++;
    return n;
}
NODE* newnode(int data){
    NODE*n = (NODE*)malloc(sizeof(NODE));
    n->info = data;
    n->left = n->right = NULL;
    return n;
}
NODE* insert(NODE*root,int data){
    NODE*n = newnode(data);
    NODE*x = root;
    NODE*y = NULL;
    while(x!=NULL){
        y = x;
        if(data <= x->info){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    if(y==NULL){
        y = n;
    }
    else if(data < y->info){
        y->left = n;
    }
    else{
        y->right = n;
    }

    return y;
}
NODE*createBST(){
   int rval,nval;
   NODE*root;
   printf("Enter the data to be stored by the node\t");
   scanf("%d",&rval);
   root = insert(root,rval);
   while(1){
       printf("Enter the data to be stored by the node\t");
       scanf("%d",&nval);
       if(nval==-1){
           break;
       }
       insert(root,nval);
   }
   return root;
}
int countNodes(NODE*root){
    if(root==NULL){
        return 0;
    }
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    int count= 0;
    enqueue(&q,root);
    while(!isEmpty(&q)){
        NODE*temp = dequeue(&q);
        count++;
        if(temp->left!=NULL){
            enqueue(&q,temp->left);
        }
        if(temp->right!=NULL){
            enqueue(&q,temp->right);
        }
    }
    return count;
}
int main(){
    NODE*root = createBST();
    printf("%d",countNodes(root));
    return 0;
}


