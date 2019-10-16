#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*left, *right;
};
typedef struct node NODE;

NODE* getNewNode(int data){
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

NODE* insertNode(NODE*root,int data){
    //creates root node of the tree structure if its empty.
    if(root == NULL){
        root = getNewNode(data);
    }
    //if data of the node to be inserted is lesser
    else if(data <= root->info){
        root->left = insertNode(root->left,data);
    }
    //if the data of the node to be inserted is greater.
    else{
        root->right = insertNode(root->right,data);
    }

    return root;

}

int search(NODE*root,int data){
    if(root==NULL){
        return -1;
    }
    else if(root->info == data){
        return 1;
    }
    else if(data <= root->info){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}

NODE* createTree(NODE*root){
    int i,data;
    while(1){
        printf("enter the integer to be stored by the node\n");
        scanf("%d",&data);
        root = insertNode(root,data);
        printf("do you want to continue?\n");
        scanf("%d",&i);
        if(i==0){
            break;
        }
    }
    return root;
}
int main(){
    NODE*root = NULL;
    root = createTree(root);
    int num;
    printf("enter a number to search in the BST\n");
    scanf("%d",&num);
    if(search(root,num) == 1){
        printf("Found");
    }
    else
    {
        printf("Not Found");
    }
    
    return 0;
}
