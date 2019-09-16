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

int main(){
    NODE*start= NULL, *last;
    last = createCircularll(start);
    displayCircularll(last);
    return 0;
}