#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*link;
};
typedef struct node NODE;
NODE*sortll(NODE*head){
    //algorithm

}
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

void sort(NODE**h){
    NODE*temp1,*temp2;
    int i,j,temp;
    for(temp1=*h;temp1!=NULL;temp1=temp1->link){
        for(temp2=temp1->link;temp2!=NULL;temp2=temp2->link){
            temp = temp1->info;
            temp1->info = temp2->info;
            temp2->info = temp;
        }
    }

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
    NODE*head = createList();
    printf("Before sorting:\t");
    displayList(head);
    sort(&head);
    printf("After sorting\t");
    displayList(head);

}