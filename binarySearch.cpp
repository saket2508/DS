#include<iostream>
using namespace std;
void swapInt(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
void sortArr(int*arr,int m){
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            if(arr[i]>arr[j]){
                swapInt(arr+i,arr+j);
            }
        }
    }
}

bool isSorted(int*arr, int m){
    for(int i=0;i<m-1;i++){
        if(arr[i]>arr[i+1]){
                return false;

        }
    }
    return true;
}

int binarySearch(int x, int*arr, int low, int high){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]== x){
            return mid;
        }
        if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }


    }
    return -1;

}
int main(){
    int m;
    cout << "Enter the size of the array" << endl;
    cin >> m;
    int*arr = new int[m];
    cout << "Enter the elements" << endl;
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to be searched" << endl;
    cin >> x;
    if(!isSorted(arr,m)){
        sortArr(arr,m);
    }
    int res = binarySearch(x,arr,0,m-1);
    if(res == -1){
        cout << "not found" << endl;
    }
    else{
        cout << "found" << endl;
    }
    delete[]arr;
    return 0;
}







