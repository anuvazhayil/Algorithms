#include<bits/stdc++.h>

using namespace std;

int main(){
    int checker = 0, flag = 0;
    string input;
    getline(cin, input);
    for(int i = 0; i < input.length(); i++){
        int value = (input[i] - 'a');
        if(checker & (1 << value)){
            flag = 1;
        }
        checker |= (1 << value);
    }
    if(flag)
        cout<<"Duplicates exists";
    else
        cout<<"Duplicates does not exist";
    return 0;
}
