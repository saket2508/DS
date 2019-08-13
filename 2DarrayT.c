#include<stdio.h>
#include<stdlib.h>
void getdata(int**array, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(array+i)+j);
        }
    }

}
void transpose(int**array, int**arrT, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            *(*(arrT+i)+j) = *(*(array+j)+i);
        }
    }


}
void displayData(int**array, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                printf("%d\t",*(*(array+i)+j));

        }
        printf("\n");
    }
}

int main(){
    int m, n;
    printf("enter the dimensions of the matrix\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int**array = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        array[i] = (int*)malloc(sizeof(int)*n);
    }
    int**arrT = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        arrT[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("enter the elements of the matrix\n");
    getdata(array,m,n);
    transpose(array,arrT,m,n);
    displayData(arrT,m,n);
    free(arrT);
    free(array);
    return 0;
}

