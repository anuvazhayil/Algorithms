void visit(string curr, unordered_map<string, multiset<string>> &airports, vector<string> &result){
    while(!airports[curr].empty()){
        string next = *airports[curr].begin();
        airports[curr].erase(airports[curr].begin());
        visit(next, airports, result);
    }
    result.push_back(curr);
}

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>>airports;
        vector<string>result;

        for(auto ele: tickets){
            airports[ele.first].insert(ele.second);
        }
        visit("JFK", airports, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
