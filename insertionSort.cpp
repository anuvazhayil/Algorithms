#include<bits/stdc++.h>

using namespace std;

int main(){
    int input, N;
    vector<int> A;
    while(cin>>input){
        A.push_back(input);
    }

    N = A.size();
    for(int i = 0; i < N; i++){
        int value = A[i], j = i-1; 
        while(j>=0 && A[j]>value){
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = value;
    }

    for(int i = 0; i < N; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
