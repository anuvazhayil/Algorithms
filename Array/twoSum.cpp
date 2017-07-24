class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>negation;
        for(int i = 0; i < nums.size(); i++){
            if(negation.find(target-nums[i]) == negation.end()){
                negation[nums[i]] = i;
            }
            else{
                return vector<int> {negation[target-nums[i]], i};
            }
        }
        return vector<int>();
    }
};
