class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;  
    }
};
/*Initialize Variables:

profit = 0 → Tracks the maximum profit so far.

minPrice = INT_MAX → Tracks the minimum stock price seen so far (initialized to a very high value).

Loop Through Each Day's Price:

For each day (i), update minPrice to be the smallest price seen so far.

Calculate the potential profit if you sell on day i (prices[i] - minPrice).

Update profit to be the maximum of the current profit and the potential profit.

Return the Maximum Profit Found:

After checking all days, profit holds the best possible profit.**/