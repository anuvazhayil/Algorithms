#include<bits/stdc++.h>

using namespace std;

int main(){
    string A;
    cin>>A;
    int len = A.size();
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    int front = 0, last = len-1, flag = 0;
    while(front < last){
        if(!isalnum(A[front])){
            front++;
            continue;
        }
        if(!isalnum(A[last])){
            last--;
            continue;
        }
        
        if(A[front] == A[last]){
            front++;
            last--;
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout<<0; //not palindrome
    }
    else
        cout<<1; //palindrome
    
    return 0;
}
