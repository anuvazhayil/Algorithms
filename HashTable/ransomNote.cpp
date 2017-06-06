#include<bits/stdc++.h>

using namespace std;

bool ransomNote(vector<string> magazine, vector<string> ransom){
    unordered_map<string, int> words;
    for(auto item: magazine){
        words[item]++;
    }
    for(auto item: ransom){
        if(words[item] > 0)
            words[item]--;
        else 
            return false;
    }
    return true;
}    

int main(){
    int m, n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        cin >> ransom[ransom_i];
    }
    if(ransomNote(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
