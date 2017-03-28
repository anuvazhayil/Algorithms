#include<bits/stdc++.h>

using namespace std;

int removedNumber(string a, string b) {
    long long int counta[26] = {0}, countb[26] = {0}, result = 0;
    
    for(int i = 0; a[i] != '\0'; i++)
        counta[a[i] - 'a']++;
    for(int i = 0; b[i] != '\0'; i++)
        countb[b[i] - 'a']++;
    
    for(int i = 0; i < 26; i++){
        result += abs(counta[i] - countb[i]);
    }
    return result;
}

int main(){
    string a, b;
    cin>>a;
    cin>>b;
    cout<<removedNumber(a, b)<<"\n";
    return 0;
}
