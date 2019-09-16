#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
    struct node*prev;
};
typedef struct node NODE;

NODE* createDoublyll(NODE*start){
    NODE*nn, *temp;
    int n = 1;
    while (n != 0) {
        nn = (NODE *) malloc(sizeof(NODE));
        printf("input the value\t");
        scanf("%d", &nn->info);
        nn->next = NULL;
        if (start == NULL) {
            start = nn;
            start->prev = NULL;
        } else {
            temp->next = nn;
            nn->prev = temp;
        }
        temp = nn;
        printf("do you wish to continue(press 0 to exit)?\t");
        scanf("%d", &n);
    }
    return start;
}

NODE* insertBeginning(NODE*start, int val){
    NODE*nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
    nn->next = start;
    start->prev = nn;
    nn->prev = NULL;
    start = nn;
    return start;
}

void insertEnd(NODE*start, int val){
    NODE*prev, *nn;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
   while(start->next!=NULL){
       start = start->next;
   }
   start->next = nn;
   nn->prev = start;
   nn->next = NULL;
}

void insertinbtw(NODE*start, int val, int pos){
    NODE*nn, *prevN;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
    int n = 1;
    while(n!=pos){
        prevN = start;
        start = start->next;
        n++;
    }
    prevN->next = nn;
    nn->prev = prevN;
    nn->next = start;
    start->prev = prevN;
}

void deleteLastNode(NODE*start){
    NODE*prev, *temp;
    temp = start;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

NODE* deleteFirstNode(NODE*start){
    NODE*nextN = start->next;
    nextN->prev = NULL;
    free(start);
    return nextN;
}

void deleteinbtw(NODE*start, int pos){
    int n = 1;
    NODE* prevN, *nextN, *temp;
    temp = start;
    while(n!=pos){
        prevN = temp;
        temp = temp->next;
        n++;
    }
    nextN = temp->next;
    free(temp);
    prevN->next = nextN;
    nextN->prev = prevN;
}

void displayDoublyll(NODE*start){
    while(start!=NULL){
        printf("%d\t",start->info);
        start = start->next;
    }
}

int main(){
    NODE*start = NULL;
    start = createDoublyll(start);
    int n;
    scanf("%d",&n);
    //n = 1 for inserting a node at the of beginning of the list
    //n = 2 for inserting a node anywhere in the middle of the list
    //n = 3 for inserting a node at the end of the list
    //n = 4 for deleting the first node
    //n = 5 for deleting a node that lies anywhere in the middle of the list
    //n = 6 for deleting the last node
    switch(n){
        case 1:
            printf("enter the value\n");
            int val;
            scanf("%d",&val);
            start = insertBeginning(start,val);
            displayDoublyll(start);
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d",&val);
            printf("enter the pos\n");
            int pos;
            scanf("%d",&pos);
            insertinbtw(start,val,pos);
            displayDoublyll(start);
            break;
        case 3:
            printf("enter the value\n");
            scanf("%d",&val);
            insertEnd(start,val);
            displayDoublyll(start);
            break;
        case 4:
            start = deleteFirstNode(start);
            displayDoublyll(start);
            break;
        case 5:
            int pos;
            printf("enter the position of the node\t");
            scanf("%d",&pos);
            deleteinbtw(start, pos);
            displayDoublyll(start);
            break;
        case 6:
            deleteLastNode(start);
            displayDoublyll(start);
            break;
        default:
            printf("enter a value between 1-6\n");
            break;
    }
    return 0;
}