class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(!n)
            return vector<int>(1,1);
        int i;
        for(i = n-1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        if(i == -1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
