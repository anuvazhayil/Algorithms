class Solution {
public:
    bool isValid(string s) {
        stack<char>brk;
        int i, n = s.size();
        for(i = 0; i < n; i++){
            if(s[i] == '(')
                brk.push(1);
            else if(s[i] == '{')
                brk.push(2);
            else if(s[i] == '[')
                brk.push(3);
            else if(s[i] == ')'){
                if(brk.empty()){
                    break;
                }
                if(brk.top() == 1)
                    brk.pop();
                else
                    break;
            }
            else if(s[i] == '}'){
                if(brk.empty()){
                    break;
                }
                if(brk.top() == 2)
                    brk.pop();
                else
                    break;
            }
            else{
                if(brk.empty()){
                    break;
                }
                if(brk.top() == 3)
                    brk.pop();
                else
                    break;
            }
        }
        if((i == n) && brk.empty())
            return true;

        return false;
    }
};
