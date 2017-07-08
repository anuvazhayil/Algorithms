class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int>seq(A.size());
        int count = 0;

        if(A.size() < 3)
            return 0;

        if((A[1] - A[0]) == (A[2] - A[1])){
            seq[2] = 1;
            count = 1;
        }

        for(int i = 3; i < A.size(); i++){
            if((A[i] - A[i-1]) == (A[i-1] - A[i-2])){
                seq[i] = seq[i-1]+1;
                count += seq[i];
            }
        }
        return count;
    }
};
