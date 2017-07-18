int dp(int s, int e, vector<vector<int>>& result){
    int temp, res = INT_MAX;
    if(s >= e)
        return 0;
    if(result[s][e])
        return result[s][e];
    for(int i = s; i <= e; i++){
        temp = i + max(dp(s, i-1, result), dp(i+1, e, result));
        res = min(res, temp);
    }
    result[s][e] = res;
    return res;
}

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>result(n+1, vector<int>(n+1));

        if(n == 1)
            return 0;

        return dp(1, n, result);
    }
};
