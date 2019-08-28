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
    printf("before inserting the new node\n");
    displayList(start);
    insertin(start,69,2);
    printf("\n After inserting the new node\n");
    displayList(start);
    return 0;
}
