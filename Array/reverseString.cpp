class Solution {
public:
    string reverseString(string s) {
        string result = s;
        for(int i = s.size()-1, j =0; i >=0; i--, j++){
            result[i] = s[j];
        }
        return result;
    }
};
