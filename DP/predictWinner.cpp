int getMax(int i, int j, vector<vector<int>>&dp, vector<int>&nums){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int left_end = nums[i] + min(getMax(i+2, j, dp, nums), getMax(i+1, j-1, dp, nums));
    int right_end = nums[j] + min(getMax(i+1, j-1, dp, nums), getMax(i, j-2, dp, nums));
    //cout<<"\n"<<left_end<<" "<<right_end;
    dp[i][j] = max(left_end, right_end);
    //cout<<"\n"<<dp[i][j];
    return dp[i][j];
}

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        /* Player 1 can decide how the game moves */
        if(len%2 == 0)
            return true;

        vector<vector<int>>dp(len, vector<int>(len, -1));
        int max_p1 = getMax(0, len-1, dp, nums);
        //cout<<"\n max 1: "<<max_p1;
        if(max_p1*2 >= accumulate(nums.begin(), nums.end(), 0)){
            return true;
        }
        else
            return false;
    }
};
