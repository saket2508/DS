#include<stdio.h>
#include<stdlib.h>
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
void reverseList(NODE*start){
    int n=1;
    NODE*iter = start;
    NODE*iter2 = start;
    while(iter->ptr!= NULL){
        n++;
        iter = iter->ptr;
    }
    int val[n];
    for(int i=0;i<n;i++){
        val[i] = start->num;
        start = start->ptr;
    }
    start = iter2;
    for(int i=n-1;i>=0;i--){
        start->num = val[i];
        start = start->ptr;
    }


}

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
    reverseList(start);
    displayList(start);
    return 0;
}