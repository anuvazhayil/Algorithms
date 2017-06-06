#include<bits/stdc++.h>

using namespace std;

int main(){
    string A;
    cin>>A;
    vector<string>result;
    int len = A.size();
    if(len > 12 || len < 4)
        cout<<"No possible address";
    
    for(int i = 1; i < 4; i++){
        string first = A.substr(0, i);
        if(first.size() > 1 && first[0] == '0')
            continue;
        if(!(stoi(first) >=0 && stoi(first) <= 255))
            continue;

        for(int j = 1; (j < 4) && ((i + j) < len); j++){
            string second = A.substr(i, j);
            if(second.size() > 1 && second[0] == '0')
                continue;
            if(!(stoi(second) >=0 && stoi(second) <= 255))
                continue;

            for(int k = 1; (k < 4) && ((i + j + k) < len); k++){
                string third = A.substr(i+j, k);
                if(third.size() > 1 && third[0] == '0')
                    continue;
                if(!(stoi(third) >=0 && stoi(third) <= 255))
                    continue;

                string fourth = A.substr(i+j+k);
                if((stoi(fourth) >=0 && stoi(fourth) <= 255) && !(fourth.size() > 1 && fourth[0] == '0')){
                    string addr = first+"."+second+"."+third+"."+fourth;
                    result.push_back(addr);
                }
            }
        }
    }
    
    for(auto item: result){
        cout<<item<<"\n";
    }
    
    return 0;
}
