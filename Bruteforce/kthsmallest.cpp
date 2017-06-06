#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> A;
    int num, k, result, i = 40;
    while(i){
        cin>>num;
        A.push_back(num);
        --i;
    }
    cout<<"Enter k:";
    cin>>k;
    int N = A.size();
    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < N ; j++){
            if(A[i] >= A[j]){
                count++;
            }
        }
        if(count == k){
            result = A[i];
        }
    }

    cout<<result<<" ";
    return 0;
}
