#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node{
    int num;
    struct node*ptr;
};
typedef struct node NODE;
NODE* createList(NODE*start) {
    NODE*nn, *temp;
    int n = 1;
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
//displays the list in order
void displayList(NODE*start){
    printf("The list in order is: \n");
    while(start!= NULL){
        printf("%d\t",start->num);
        start = start->ptr;
    }
}
int main(){
    NODE*start = NULL;
    NODE*res = createList(start);
    displayList(res);
    return 0;
}
