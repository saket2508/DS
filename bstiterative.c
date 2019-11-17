#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*left,*right;
};
typedef struct node NODE;
struct stack{
    int top;
    NODE* arr[100];
};
typedef struct stack STACK;
int isEmpty(STACK*s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isFull(STACK*s){
    if(s->top==99){
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
NODE* top(STACK*s){
    if(isEmpty(s)){
        return NULL;
    }
    NODE*n = s->arr[s->top];
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

NODE*createBST(int nnodes){
    int rval,nval;
    printf("Enter the data to be stored by the nodes of the BST sequentially\n");
    scanf("%d",&rval);
    NODE*root = newnode(rval);
    int n=1;
    while(n<nnodes){
        scanf("%d",&nval);
        insert(root,nval);
        n++;
    }
    return root;
}

void postorderTraversal(NODE*root){
    if(root == NULL){
        return ;
    }
    STACK*s1 = (STACK*)malloc(sizeof(STACK));
    STACK*s2 = (STACK*)malloc(sizeof(STACK));
    s1->top = s2->top = -1;
    push(s1,root);
    while(!isEmpty(s1)){
        NODE*temp = pop(s1);
        push(s2,temp);
        if(temp->left!=NULL){
            push(s1,temp->left);
        }
        if(temp->right!=NULL){
            push(s1,temp->right);
        }
    }
    while(!isEmpty(s2)){
        NODE*temp = pop(s2);
        printf("%d\t",temp->info);
    }
}

void preorderTraversal(NODE*root){
    if(root==NULL){
        return ;
    }
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    push(s,root);
    while(!isEmpty(s)){
        NODE*temp = pop(s);
        printf("%d\t",temp->info);
        if(temp->right!=NULL){
            push(s,temp->right);
        }
        if(temp->left!=NULL){
            push(s,temp->left);
        }
    }
}

void inorderTraversal(NODE*root){
    STACK*s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    NODE*temp = root;
    while(temp!=NULL || !isEmpty(s)){
        while(temp!=NULL){
            push(s,temp);
            temp = temp->left;
        }
        temp = pop(s);
        printf("%d\t",temp->info);
        temp = temp->right;
    }
}
void main(){
    NODE*root = createBST(7);
    postorderTraversal(root);
}