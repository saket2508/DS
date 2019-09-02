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
        printf("do you wish to continue(press 0 to exit)?\t");
        scanf("%d", &n);

    }
    return start;
}
void mergeAlternateNodes(NODE*start1, NODE*start2){
    NODE*temp1;
    NODE*temp2;
    while(start1!=NULL && start2!=NULL){
        temp1 = start1->ptr;
        temp2 = start2;
        start1->ptr = temp2;
        temp2->ptr = temp1;
        start1 = temp1;
        start2 = start2->ptr;
    }

}
//displays the list in order
void displayList(NODE*start){
    printf("The list in order is: \n");
    while(start!= NULL){
        printf("%d\t",start->num);
        start = start->ptr;
    }
}
int main(){
    NODE*start1 = NULL;
    NODE*start2 = NULL;
    printf("FIRST LINKED LIST\n");
    start1 = createList(start1);
    printf("SECOND LIST\n");
    start2 = createList(start2);
    mergeAlternateNodes(start1,start2);
    displayList(start1);

}
