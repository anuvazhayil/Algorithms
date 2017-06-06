#include<bits/stdc++.h>

using namespace std;

int main(){
    int numb1, numb2, count = 0;
    int xorval;
    cin>>numb1>>numb2;
    
    xorval = numb1 ^ numb2;
    for(int i = xorval; i != 0; i = i & (i - 1)){
        count++;
    }
    cout<<"The number of bits to be flipped is: "<<count;
    return 0;
}
