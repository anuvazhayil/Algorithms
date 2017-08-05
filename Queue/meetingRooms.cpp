/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval &a, Interval &b){
    return (a.start < b.start);
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        if(!intervals.size())
            return 0;
        int count = 1;
        priority_queue<int, vector<int>, greater<int>>q;
        q.push(-1);
        for(int i = 0; i < intervals.size(); i++){

            if(intervals[i].start >= q.top()){
                q.pop();
            }
            else{
                cout<<intervals[i].start<<q.top();
                count++;
            }
            q.push(intervals[i].end);
        }
        return count;
    }
};
