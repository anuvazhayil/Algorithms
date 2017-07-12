int checkCombinations(vector<int>& nums, int target, vector<int>& comb){
    int count = 0;

    if(!target)
        return 1;
    if(comb[target] != -1)
        return comb[target];
    for(int i = 0; i < nums.size(); i++){
        if(target-nums[i] >=0)
            count += checkCombinations(nums, target-nums[i], comb);
    }

    comb[target] = count;
    return count;
}

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>comb(target+1, -1);

        if(!nums.size())
            return 0;

        return checkCombinations(nums, target, comb);
    }
};
