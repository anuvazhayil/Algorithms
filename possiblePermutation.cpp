#include<bits/stdc++.h>

using namespace std;

bool checkdup(vector<int>num, int i, int j){
    for(int k = i; k < j; k++){
        if(num[k] == num[j])
            return true;
    }
    return false;
}

void recPermute(vector<int>num, int beg, int end, vector<vector<int> >&result){
    if(beg == end){
        result.push_back(num);
    }
    else{
        for(int i = beg; i <= end; i++){
            
            if(checkdup(num, beg, i))
                continue;

            int temp = num[i];
            num[i] = num[beg];
            num[beg] = temp;

            recPermute(num, beg+1, end, result);
            
            temp = num[i];
            num[i] = num[beg];
            num[beg] = temp;
        }
    }
}

int main(){
    vector<int>num;
    vector<vector<int> >result;
    int n, ele;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ele;
        num.push_back(ele);
    }
    recPermute(num, 0, n-1, result);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < num.size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
