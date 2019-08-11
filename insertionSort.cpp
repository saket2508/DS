#include<iostream>
using namespace std;

void insertionSort(int*arr, int m){
    int i, key, j;
    for(int i=1;i<m;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] >key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;

    }

}
void getData(int*arr, int m){
    cout << "enter the elements" << endl;
    for(int i=0;i<m;i++){
        cin>> arr[i];
    }

}
void printdata(int*arr, int m){
    cout << "Elements in Sorted order are:" << endl;
    for(int i=0;i<m;i++){
        cout << arr[i] << "\t";
    }

}
int main(){
    int m;
    cout<< "Enter the size of the array\n";
    cin>> m;
    int*arr = new int[m];
    getData(arr,m);
    insertionSort(arr,m);
    printdata(arr,m);
    delete[]arr;


return 0;
}
