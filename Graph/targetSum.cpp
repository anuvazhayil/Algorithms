void dfs(vector<int> &nums, int S, int i, int &count, int sum){
    if((i == nums.size()-1) && (sum == S)){
        count++;
    }
    if(i+1 < nums.size()){
        dfs(nums, S, i+1, count, sum+nums[i+1]);
        dfs(nums, S, i+1, count, sum-nums[i+1]);
    }
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        if(!nums.size())
            return 0;
        dfs(nums, S, 0, count, nums[0]);
        dfs(nums, S, 0, count, -nums[0]);
        return count;
    }
};
