class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy_price = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            buy_price = min(buy_price, prices[i]);
            ans = max(ans, prices[i] - buy_price);
        }

        return ans;
    }
};
