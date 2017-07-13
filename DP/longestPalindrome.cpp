class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<int>v(len), v1(len,1), v2(len);

        for(int i = 2; i <= len; i++){
            for(int j = 0; j < len-i+1; j++){
                if(s[j] == s[i+j-1])
                    v[j] = 2 + v2[j+1];
                else
                    v[j] = max(v1[j], v1[j+1]);
            }
            swap(v1,v2);
            swap(v1,v);
        }
        return v1[0];
    }
};
