class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())
            return 0;

        int maximum, n = nums.size();
        vector<int>sum(n);
        maximum = sum[0] = nums[0];

        for(int i = 1; i < n; i++){
            sum[i] = nums[i] + ((sum[i-1] > 0)? sum[i-1]: 0);
            maximum = max(sum[i],maximum);
        }
        /*for(int i = 0; i < n; i++){
            for(int j = i+1; j < n+1; j++){
                if((sum[j] - sum[i]) > max){
                    max = sum[j] - sum[i];
                }
            }
        }*/
        return maximum;
    }
};
