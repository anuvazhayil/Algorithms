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
    vector<int>partlim;
    partlim.push_back(low);
    partlim.push_back(high);
    while(partlim.size()){
        high = partlim.back();
        partlim.pop_back();
        low = partlim.back();
        partlim.pop_back();
        
        int pos = partitionAlgo(arr, low, high);
        if(pos-1 > low){
            partlim.push_back(low);
            partlim.push_back(pos-1);
        }
        if(pos+1 < high){
            partlim.push_back(pos+1);
            partlim.push_back(high);
        }
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
