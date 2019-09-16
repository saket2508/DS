#include <stdio.h>
#include <stdlib.h>
struct node{
    int num;
    struct node*ptr;
};
typedef struct node NODE;
NODE* createList(NODE*start) {
    NODE *nn;
    NODE*temp;
    int n;
    while (n != 0) {
        nn = (NODE *) malloc(sizeof(NODE));
        printf("input the value\t");
        scanf("%d", &nn->num);
        nn->ptr = NULL;
        if (start == NULL) {
            start = nn;
        } else {
            temp->ptr = nn;
        }
        temp = nn;
        printf("do you wish to continue?(Press 0 to exit)\t");
        scanf("%d", &n);

    }
    return start;
}
//for inserting a node at the beginning of the list
NODE* Beginning(NODE*start, int val){
    NODE*nn;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->num = val;
    nn->ptr = start;
    start = nn;
    return start;
}
//for inserting a node at the end of the list
void End(NODE*start, int val){
    while(start->ptr != NULL){
        start = start->ptr;
    }
    NODE*nn;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->num = val;
    start->ptr = nn;
    nn->ptr = NULL;
}
//for inserting a node anywhere in the middle of the list
void insertin(NODE*start,int val, int pos){
    int n=1;
    while(n!= pos-1){
        n++;
        start = start->ptr;
    }
    NODE*temp;
    NODE*nn;
    nn = (NODE*)malloc(sizeof(NODE));
    nn->num = val;
    temp = start->ptr;
    start->ptr = nn;
    nn->ptr = temp;

    
}
//deletes the last node
void deleteLastNode(NODE*start){
    NODE*prev;
    while(start->ptr!= NULL){
        prev = start;
        start = start->ptr;
    }
    prev->ptr = NULL;
    free(start);

}
//deletes the selected node in the middle of the list
void deleteinbtw(NODE*start, int pos){
    int n=1;
    NODE*prev;
    while(n!= pos){
        n++;
        prev = start;
        start = start->ptr;
    }
    NODE*next = start->ptr;
    prev->ptr = next;
    free(start);

}
//deletes the first node
NODE*deleteFirstNode(NODE*start){
    NODE*sec = start->ptr;
    free(start);
    return sec;
}
//displays the elements of the list in order
void displayList(NODE*start){
    printf("The list in order is: \n");
    while(start!= NULL){
        printf("%d\t",start->num);
        start = start->ptr;
    }
}
int main(){
    NODE*start = NULL;
    start = createList(start);
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
            start = Beginning(start,val);
            displayList(start);
            break;
        case 2:
            printf("enter the value\n");
            scanf("%d",&val);
            printf("enter the pos\n");
            int pos;
            scanf("%d",&pos);
            insertin(start,val,pos);
            displayList(start);
            break;
        case 3:
            printf("enter the value\n");
            scanf("%d",&val);
            End(start,val);
            displayList(start);
            break;
        case 4:
            start = deleteFirstNode(start);
            displayList(start);
            break;
        case 5:
            int pos;
            printf("enter the position of the node\t");
            scanf("%d",&pos);
            deleteinbtw(start, pos);
            displayList(start);
            break;
        case 6:
            deleteLastNode(start);
            displayList(start);
            break;
        default:
            printf("enter a value between 1-6\n");
            break;
    }
    return 0;
}
