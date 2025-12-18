"""
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
"""

from typing import List
class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        k2 = k // 2
        profit = [strategy[i] * prices[i] for i in range(n)]

        prefixP = [0] * (n + 1)
        prefixA = [0] * (n + 1)
        for i in range(n):
            prefixP[i + 1] = prefixP[i] + prices[i]
            prefixA[i + 1] = prefixA[i] + profit[i]

        og_profit = prefixA[n]
        max_delta = 0
        for l in range(n - k + 1):
            delta = (prefixP[l + k] - prefixP[l + k2]) - (prefixA[l + k] - prefixA[l])
            if delta > max_delta:
                max_delta = delta
        return og_profit + max_delta