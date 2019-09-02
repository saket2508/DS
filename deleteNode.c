#include <stdio.h>
#include <stdlib.h>
struct node{
    int num;
    struct node*ptr;
};
typedef struct node NODE;
//creates a linked list by taking inputs from the user
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
        printf("do you wish to continue(press 0 to exit)?\t");
        scanf("%d", &n);

    }
    return start;
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
    while(start!= NULL){
        printf("%d\t",start->num);
        start = start->ptr;
    }
}
int main(){
    NODE*start = NULL;
    start = createList(start);
    printf("the list before deleting the selected node is:\n");
    displayList(start);
    printf("\n");
    deleteinbtw(start,2);
    printf("the list after deleting the selected node is\n");
    displayList(start);
    return 0;
}
