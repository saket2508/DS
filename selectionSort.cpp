#include<iostream>
using namespace std;
void swapInt(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int*arr, int m){
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            if(arr[i]>arr[j]){
                swapInt(arr+i,arr+j);
            }
        }
    }


}
void getData(int*arr, int m){
    cout << "Enter the elements one by one\n";
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
}
void printData(int*arr, int m){
    cout << "Array in sorted order is: ";
    for(int i=0;i<m;i++){
        cout << arr[i] << "\t";
    }
}
int main(){
int m;
cout << "enter the size of the array" << endl;
cin>> m;
int*arr = new int[m];
getData(arr,m);
SelectionSort(arr,m);
printData(arr,m);
return 0;


}
