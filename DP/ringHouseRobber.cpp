class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        if(n == 1)
            return nums[0];

        vector<int>withFirst(n-1);
        vector<int>withLast(n-1);

        for(int i = 0; i < n-1; i++){
            withFirst[i] = nums[i];
            withLast[i] = nums[i+1];
        }

        int f_included = 0, f_excluded = 0, l_included = 0, l_excluded = 0;
        for(int i = 0; i < n-1; i++){
            int temp1 = f_included, temp2 = l_included;
            f_included = withFirst[i] + f_excluded;
            f_excluded = max(temp1, f_excluded);
            l_included = withLast[i] + l_excluded;
            l_excluded = max(temp2, l_excluded);
        }
        int f_max = max(f_included, f_excluded);
        int l_max = max(l_included, l_excluded);
        return max(f_max, l_max);
    }
};
