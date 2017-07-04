class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int pro_price = 0, min_val = prices[0];
        for(int i = 0; i < prices.size(); i++){
            pro_price = max(pro_price, prices[i]-min_val);
            min_val = min(min_val, prices[i]);
        }
        return pro_price;
    }
};
