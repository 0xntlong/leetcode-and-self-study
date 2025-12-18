/**
3652. Best Time to Buy and Sell Stock using Strategy
    You are given two integer arrays prices and strategy, where:
    prices[i] is the price of a given stock on the ith day.
    strategy[i] represents a trading action on the ith day, where:
    -1 indicates buying one unit of the stock.
    0 indicates holding the stock.
    1 indicates selling one unit of the stock.
    You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:
    Selecting exactly k consecutive elements in strategy.
    Set the first k / 2 elements to 0 (hold).
    Set the last k / 2 elements to 1 (sell).
    The profit is defined as the sum of strategy[i] * prices[i] across all days.
    Return the maximum possible profit you can achieve.
    Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.

    
    Example :
    Input: prices = [4,2,8], strategy = [-1,0,1], k = 2
    Output: 10
    Explanation:
    Modification	Strategy	Profit Calculation	Profit
    Original	[-1, 0, 1]	(-1 x 4) + (0 x 2) + (1 x 8) = -4 + 0 + 8	4
    Modify [0, 1]	[0, 1, 1]	(0 x 4) + (1 x 2) + (1 x 8) = 0 + 2 + 8	10
    Modify [1, 2]	[-1, 0, 1]	(-1 x 4) + (0 x 2) + (1 x 8) = -4 + 0 + 8	4
    Thus, the maximum possible profit is 10, which is achieved by modifying the subarray [0, 1]. 
 */



#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int k2 = k / 2;
        
        vector<long long> profit(n);
        for (int i = 0; i < n; i++) {
            profit[i] = strategy[i] * prices[i];
        }

        vector<long long> prefixP(n + 1, 0), prefixA(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixP[i + 1] = prefixP[i] + prices[i];
            prefixA[i + 1] = prefixA[i] + profit[i];
        }

        long long og_profit = prefixA[n];
        long long max_delta = 0;
        
        for (int l = 0; l <= n - k; l++) {
            long long delta = (prefixP[l + k] - prefixP[l + k2]) - (prefixA[l + k] - prefixA[l]);
            max_delta = max(max_delta, delta);
        }

        return og_profit + max_delta;
    }
};