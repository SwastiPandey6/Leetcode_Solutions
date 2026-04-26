// 121. Best Time to Buy and Sell Stock
// Difficulty: Easy
// Approach: Track minimum price and max profit
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};