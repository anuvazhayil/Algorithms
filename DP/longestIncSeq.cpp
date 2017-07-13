class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        vector<int>max_len(len,1);
        for(int i = 1; i < len; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    max_len[i] = max(max_len[i], max_len[j]+1);
                }
            }
        }

        sort(max_len.begin(), max_len.end());
        return max_len[len-1];
    }
};
