#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node*ptr;
};
typedef struct node NODE;

void displayPolynomial(NODE*start){
    while(start->ptr!=NULL){
        printf("%dx**%d +  ",start->coeff,start->power);
        start = start->ptr;
    }
    printf("%dx**%d ",start->coeff,start->power);
    printf("\n");

}

NODE* polynomial(NODE*start){
    NODE* nn = NULL, *temp = NULL;
    int n = 1;
    while(n!=0){
        nn = (NODE*)malloc(sizeof(NODE));
        printf("Enter the coefficient of the term\t");
        scanf("%d",&nn->coeff);
        printf("Enter the power of the term\t");
        scanf("%d",&nn->power);
        nn->ptr = NULL;
        if(start == NULL){
            start == nn;
        }
        else{
            temp->ptr = nn;
        }
        temp = nn;
        printf("do you wish to continue\t");
        scanf("%d",&n);
    }
    displayPolynomial(start);
    return start;
}

NODE* addPolynomials(NODE*start1, NODE*start2){
    NODE*temp = start2;
    while(start1!=NULL){
        while(start2!=NULL){
            if(start1->power == start2->power){
                start1->coeff += start2->coeff;
            }
            start2 = start2->ptr;
        }
        start2 = temp;
        start1 = start1->ptr;
    }
    return start1;
}

int main(){
    NODE*p1 = NULL, *p2 = NULL, *res = NULL;
    p1 = polynomial(p1);
    displayPolynomial(p1);
    p2 = polynomial(p2);
    displayPolynomial(p2);
    return 0;
}