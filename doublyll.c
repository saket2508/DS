#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void displayDoublyll(NODE*start){
    while(start!=NULL){
        printf("%d\t",start->info);
        start = start->next;
    }
}

int main(){
    NODE*start = NULL;
    start = createDoublyll(start);
    displayDoublyll(start);
    return 0;
}