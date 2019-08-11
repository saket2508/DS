#include<iostream>
using namespace std;
void swapInt(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

void bubbleSort(int*arr, int m){
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapInt(arr+j,arr+j+1);
            }
        }
    }


}
void getData(int*arr, int m){
    cout << "enter the elements one by one\n";
    for(int i=0;i<m;i++){
        cin>> arr[i];
    }

}

void printData(int*arr, int m){
    cout << "Array elements in sorted order are: " << endl;
    for(int i=0;i<m;i++){
        cout << arr[i] << "\t";
    }

}
int main(){
    int m;
    cout << "enter the size of the array\n";
    cin>> m;
    int*arr = new int[m];
    getData(arr,m);
    bubbleSort(arr,m);
    printData(arr,m);
    delete[]arr;
    return 0;



}
