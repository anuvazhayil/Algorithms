class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < 2){
            return false;
        }
        vector<int>sum(len+1,0);
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i] && !nums[i+1])
                return true;
            sum[i+1] = sum[i] + nums[i];
        }
        if(k == 0)
            return false;

        for(int i = 0; i < len-1; i++){
            for(int j = i+2; j <= len; j++){
                if((sum[j] - sum[i]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};
