#include<bits/stdc++.h>

using namespace std;

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partitionAlgo(vector<int>&arr, int low, int high){
    int i = low-1;
    int pivot = arr[high];
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[++i], &arr[high]);
    return i;
}

void quickSort(vector<int>&arr, int low, int high){

    if(low < high){
        int pos = partitionAlgo(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, high);
    }
}

void print(vector<int>arr){
    int len = arr.size();
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";    
    }
    cout<<"\n";
}

int main(){
    vector<int>arr;
    int size, ele;
    cout<<"Enter the size: "; cin>>size;
    
    for(int i = 0; i < size; i++){
        cin>>ele;
        arr.push_back(ele);
    }
    quickSort(arr, 0, size-1);
    print(arr);

    return 0;
}
