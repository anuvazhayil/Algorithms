class MinStack {
public:
    /** initialize your data structure here. */
    vector<int>s;
    MinStack() {

    }

    void push(int x) {
        s.push_back(x);

    }

    void pop() {
        s.pop_back();
    }

    int top() {
        return s.back();
    }

    int getMin() {
        int n = s.size(), min = s[0];
        for(int i = 1; i < n; i++){
            if(s[i] < min)
                min = s[i];
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
