class Solution {
public:
    int longestValidParentheses(string s) {
        int max_val = 0;
        stack<int>index;

        if(!s.length())
            return max_val;
        index.push(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                index.push(i);
            }
            else{
                index.pop();
                if(index.empty()){
                    index.push(i);
                }
                else{
                    max_val = max(max_val, i - index.top());
                }
            }
        }

        return max_val;
    }
};
