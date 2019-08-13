#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void getData(int**arr, int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",*(arr+i)+j);
        }
    }
}
void displayData(int**arr, int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",*(*(arr+i)+j));
        }
    }
}
bool isLowerTriangular(int**arr, int m){
    for(int i=1;i<m;i++){
        for(int j=m-1;j>i;j--){
                if(*(*(arr+i)+j)!=0){
                    return false;
                }

        }
    }
    return true;


}
int main(){
int m;
printf("enter the size of the square matrix\n");
scanf("%d",&m);
int**arr = (int**)malloc(sizeof(int*)*m);
for(int i=0;i<m;i++){
    arr[i] = (int*)malloc(sizeof(int)*m);
}
printf("enter the elements of the square matrix\n");
getData(arr,m);
if(isLowerTriangular(arr,m)){
    printf("YES");
}
else{
    printf("NO");
}

free(arr);


return 0;
}
