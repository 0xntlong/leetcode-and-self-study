"""
1833. Maximum Ice Cream Bars
    It is a sweltering summer day, and a boy wants to buy some ice cream bars.
    At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
    Note: The boy can buy the ice cream bars in any order.
    Return the maximum number of ice cream bars the boy can buy with coins coins.
    You must solve the problem by counting sort.

    Example :
    Input: costs = [1,3,2,4,1], coins = 7
    Output: 4
    Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
"""

from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        maxCost = max(costs)
        freq = [0] * (maxCost + 1)
        for cost in costs:
            freq[cost] += 1
        res = 0
        for cost in range(1, maxCost + 1):
            if freq[cost] == 0:
                continue
            can_buy = min(freq[cost], coins // cost)
            res += can_buy
            coins -= can_buy * cost
            if coins < cost:
                break
        return res