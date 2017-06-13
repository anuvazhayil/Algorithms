#include<bits/stdc++.h>

using namespace std;

int possPath(int curr, int n, vector<int>&cache){
    if(curr > n) return 0;
    if(curr == n) return 1;
    int& npath = cache[curr];
    if(npath != -1){
        return npath;
    }
    npath = 0;
    npath += possPath(curr+1, n, cache);
    npath += possPath(curr+2, n, cache);
    return npath;
}

int main(){
    int steps;
    cin>>steps;
    vector<int>cache(steps+1, -1);
    //all the possible combinations to reach n
    int result = possPath(0, steps, cache);
    cout<<"Possible number of paths: "<<result;
    return 0;
}
