void findComb(vector<vector<int>>&result, vector<int>&one_set, int n, int k){
    int i;
    if((one_set.size() == k) && (!n)){
        result.push_back(one_set);
        return;
    }
    if(one_set.empty())
        i = 1;
    else
        i = one_set.back()+1;

    for(; i <= 9; i++){
        if((n - i) >= 0){
            one_set.push_back(i);
            findComb(result, one_set, n-i, k);
            one_set.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>one_set;
        int max = 0, high = 9, min = 0;
        for(int i = 0; i < k; i++){
            max += high - i;
            min += i+1;
        }
        if(n > max || n < min)
            return result;

        findComb(result, one_set, n, k);
        return result;
    }
};
