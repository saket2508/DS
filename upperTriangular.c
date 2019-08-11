#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool isUpperTriangular(int**arr, int m){
for(int i=1;i<m;i++){
    for(int j=0;j<i;j++){
        if(*(*(arr+i)+j)!=0){
            return false;
        }
    }
}
return true;
}
void getData(int**arr, int m){
for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        scanf("%d",*(arr+i)+j);
    }
}
}

int main(){
int m;
printf("enter the size of the square matrix\n");
scanf("%d",&m);
int**arr = (int**)malloc(sizeof(int)*m);
for(int i=0;i<m;i++){
    arr[i] =(int*)malloc(sizeof(int)*m);
}
printf("enter the elements\n");
getData(arr,m);
if(isUpperTriangular(arr,m)){
    printf("YES");}
else{
    printf("NO");
}
free(arr);


return 0;
}
