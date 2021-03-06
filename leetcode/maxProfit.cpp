class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        for(i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            if(diff > 0) {
                profit += diff;
            }
        }
        return profit;
    }
};