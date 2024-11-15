"""
1672. Richest Customer Wealth
    You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the ith customer has in the jth bank. Return the wealth that the richest customer has.
    A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

    Example :
    Input: accounts = [[1,2,3],[3,2,1]]
    Output: 6
    Explanation:
    1st customer has wealth = 1 + 2 + 3 = 6
    2nd customer has wealth = 3 + 2 + 1 = 6
    Both customers are considered the richest with a wealth of 6 each, so return 6.
"""

from typing import List
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        richest = 0
        m = len(accounts)
        n = len(accounts[0])
        for i in range(0, m):
            total = 0
            for j in range(0, n):
                total += accounts[i][j]
                richest = max(richest, total)
        return richest