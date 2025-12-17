/**
3573. Best Time to Buy and Sell Stock V
    You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
    You are allowed to make at most k transactions, where each transaction can be either of the following:
    Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
    Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
    Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
    Return the maximum total profit you can earn by making at most k transactions.

    Example :
    Input: prices = [1,7,9,8,2], k = 2
    Output: 14
    Explanation:

    We can make $14 of profit through 2 transactions:
    A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
    A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.
 */

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<long long> profit(k + 1, 0);
        vector<long long> buy(k + 1, -1e9);
        vector<long long> sell(k + 1, 0);
        for (const auto& p : prices){
            for (int i = 0; i < k; i++){
                profit[i] = max(max(profit[i], buy[i+1] + p), sell[i+1] - p);
                buy[i+1] = max(buy[i + 1], profit[i+1] - p);
                sell[i+1] = max(sell[i + 1], profit[i+1] + p);
            }
        }
        return *max_element(profit.begin(), profit.end());
    }
};