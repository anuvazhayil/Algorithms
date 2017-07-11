class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int uni_dig = 1;

        if(!n)
            return 1;

        for(int i = 1, j = 9; i < n; i++, j--){
            uni_dig *= j;
        }
        uni_dig *= 9;

        return uni_dig + countNumbersWithUniqueDigits(n-1);
    }
};
