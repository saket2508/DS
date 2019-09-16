#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
typedef struct node NODE;
NODE* createCircularll(NODE*start){
    NODE*nn, *temp;
    int n = 1;
    while(n!=0){
        nn = (NODE*)malloc(sizeof(NODE));
        printf("input the value of the node\t");
        scanf("%d",&nn->info);
        if(start==NULL){
            start = nn;
        }
        else{
            temp->next = nn;
        }
        temp = nn;
        temp->next = start;
        printf("do you wish to continue(Press 0 to exit)\t");
        scanf("%d",&n);
    }
    return temp;
}

void displayCircularll(NODE*last){
    NODE*start = last->next;
    while(start!=last){
        printf("%d\t",start->info);
        start = start->next;
    }
    printf("%d\t",last->info);

}

void insertBeginning(NODE*last, int val){
    NODE*nextN, *nn;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
    nextN = last->next;
    last->next = nn;
    nn->next = nextN;
}

NODE* insertEnd(NODE*last, int val){
    NODE*nn, *prev, *first;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
    first = last->next;
    last->next = nn;
    nn->next = first;
    last = nn;
    return last;
}

void insertinbtw(NODE*last, int val, int pos){
    NODE*prev, *nn;
    int n = 0;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->info = val;
    while(n!= pos){
        prev = last;
        last = last->next;
        n++;
    }
    prev->next = nn;
    nn->next = last;

}

void deleteFirstNode(NODE*last){
    NODE *nextN, *start;
    start = last->next;
    nextN = start->next;
    last->next = nextN;
    free(start);

}

NODE* deleteLastNode(NODE*last){
    NODE *nextN, *prev, *start;
    start = last->next;
    while(start!=last){
        prev = start;
        start = start->next;
    }
    nextN = last->next;
    prev->next = nextN;
    free(start);
    last = prev;
    return last;
    
}

void deleteinbtw(NODE*last, int pos){
    int n = 0;
    NODE* prev, *nextN;
    while(n!=pos){
        prev = last;
        last = last->next;
        n++;
    }
    nextN = last->next;
    prev->next = nextN;
    free(last);
}



int main(){
    NODE*start = NULL, *last;
    last = createCircularll(start);
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
            insertBeginning(last,val);
            displayCircularll(last);
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d",&val);
            printf("enter the pos\n");
            int pos;
            scanf("%d",&pos);
            insertinbtw(last,val,pos);
            displayCircularll(last);
            break;
        case 3:
            printf("enter the value\n");
            scanf("%d",&val);
            insertEnd(last,val);
            displayCircularll(last);
            break;
        case 4:
            deleteFirstNode(last);
            displayCircularll(last);
            break;
        case 5:
            int pos;
            printf("enter the position of the node\t");
            scanf("%d",&pos);
            deleteinbtw(last, pos);
            displayCircularll(last);
            break;
        case 6:
            last = deleteLastNode(last);
            displayList(last);
            break;
        default:
            printf("enter a value between 1-6\n");
            break;
    }
    return 0;
}