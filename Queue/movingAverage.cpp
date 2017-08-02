class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int>q;
    int limit, sum = 0;
    MovingAverage(int size) {
        this->limit = size;
    }

    double next(int val) {
        int n = 0;
        if(q.size() < limit)
             q.push(val);
        else{
            n = q.front();
            q.pop();
            q.push(val);
        }

        sum += val - n;
        return (double)sum/(double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
