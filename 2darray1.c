#include <stdio.h>
#include <stdlib.h>

void getData(int**arr,int p,int q){
    printf("ENTER THE ELEMENTS OF THE MATRIX\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",*(arr+i)+j);
        }
    }
}
void printData(int**arr,int p,int q){
    printf("ARRAY ELEMENTS IN ORDER ARE: ");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d\t",*(*(arr+i)+j));
        }
        printf("\n");
    }
}
int main() {
    int p;
    int q;
    printf("ENTER THE DIMENSIONS\n");
    scanf("%d",&p);
    scanf("%d",&q);
    int **arr = (int **) malloc(sizeof(int) * p);
    for(int i=0;i<=p;i++){
        arr[i] = (int*)malloc(sizeof(int)*q);
    }
    getData(arr,p,q);
    printData(arr,p,q);
    free(arr);
    return 0;



}

