#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch; int len, count = 0; 
    vector<char> s;
    unordered_map<char,int> counter;
    while(cin>>ch){
        s.push_back(ch);
    }
    len = s.size();
    for(int i = 0; i < len; i++){
        ++counter[s[i]];
    }
    
    for(auto it: counter){
        if(it.second % 2 != 0)
            count++;
    }

    if((len%2 == 0 && count == 0) || (len%2 != 0 && count == 1))
        cout<<"\n It's a palindrome permutation";
    else
        cout<<"\n It's not a palindrome permutation";
    return 0;
}
