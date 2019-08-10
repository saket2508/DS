#include<stdio.h>
#include<stdlib.h>

int** multiply(int**arr1, int**arr2, int m, int n, int q){
    //A FUNCTION WITH A DOUBLE POINTER RETURN TYPE
    int**res = (int**)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        res[i] = (int*)malloc(sizeof(int)*q);

    }
    for(int i=0;i<m;i++){

        for(int j=0;j<q;j++){

            *(*(res+i)+j) = 0;

            for(int k=0;k<n;k++){

                int x = *(*(arr1+i)+k);
                int y=  *(*(arr2+k)+j);
                *(*(res+i)+j) += x*y;


            }
        }
    }
    return res;
}
void displayArray(int**res,int m, int q){

    printf("THE RESULTING ARRAY IS:\n");

    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            printf("%d\t",*(*(res+i)+j));
        }
        printf("\n");
    }


}
void getData(int**arr1,int m, int n){
    printf("enter the dimensions of the array: ");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(arr1+i)+j);
        }
        printf("\n");
    }
}

int main(){
    int m, n;
    int p, q;
    printf("enter the dimensions of the first array\n");
    scanf("%d\n%d",&m,&n);
    printf("enter the dimensions of the second array\n");
    scanf("%d\n%d",&p,&q);
    int**arr1 = (int**)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        arr1[i] = (int*)malloc(sizeof(int)*n);
        }
    int**arr2 = (int**)malloc(sizeof(int)*p);
    for(int i=0;i<p;i++){
        arr2[i] = (int*)malloc(sizeof(int)*q);
    }
    if(p!=n){
        printf("FOR THE MULTIPLICATION OF TWO MATRICES, IT IS NECESSARY THAT THEIR ORDER BE SAME");
        exit(10);
    }
    getData(arr1,m,n);
    getData(arr2,n,q);
    int**res;
    res = multiply(arr1,arr2,m,n,q);
    displayArray(res,m,q);
    free(arr1);
    free(arr2);
    free(res);


    return 0;






}
