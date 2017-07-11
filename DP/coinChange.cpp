class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int>sum(amount+1, -1);
        sum[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; (coins[j] <= i) && (j < coins.size()); j++){
                if((sum[i-coins[j]] != -1)){
                    if((sum[i] == -1) ^ (sum[i-coins[j]]+1 < sum[i]))
                        sum[i] = 1 + sum[i-coins[j]];
                }
            }
        }
        return sum[amount];
    }
};
