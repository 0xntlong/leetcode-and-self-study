"""
2110. Number of Smooth Descent Periods of a Stock
    You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
    A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
    Return the number of smooth descent periods.

    Example :
    Input: prices = [3,2,1,4]
    Output: 7
    Explanation: There are 7 smooth descent periods:
    [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
    Note that a period with one day is a smooth descent period by the definition.
"""

from typing import List
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        res = 0
        length = 1
        prev = float('inf')
        for price in prices:
            if prev - price == 1:
                length += 1
            else:
                res += (length * (length + 1)) // 2
                length = 1
            prev = price
        res += (length * (length + 1)) // 2
        return res - 1