class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = -1, i = 0;
        while(i < s.size()){
            pos = t.find(s[i], pos+1);
            if(pos == string::npos)
                return false;
            ++i;
        }
        return true;
    }
};
