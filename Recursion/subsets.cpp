#include<bits/stdc++.h>

using namespace std;

vector<string> subsets(vector<char> set){
    int N = set.size();
    vector<string> temp;

    if(N == 1){
        string s(1,set[0]);
        temp.push_back(s);
        return temp;
    }
    else if(N > 1){
        char ch;
        ch = set[N-1];
        set.pop_back();
        temp = subsets(set);
        int length = temp.size();
        for(int i = 0; i < length; i++){
            string sub = temp[i]+ch;
            temp.push_back(sub);
        }
        return temp;
    }
}

int main(){
    vector<char> sets;
    vector<string> subset;
    char ch;
    cout<<"Enter the string:";
    while(cin>>ch){
        sets.push_back(ch);
    }
    subset = subsets(sets);
    int len = subset.size();
    cout<<"Substrings: ";
    for(int i = 0; i < len; i++){
        cout<<subset[i]<<" ";
    }
    return 0;
}
