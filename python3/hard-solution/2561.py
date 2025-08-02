"""
2561. Rearranging Fruits 
    You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

    Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
    The cost of the swap is min(basket1[i],basket2[j]).
    Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

    Return the minimum cost to make both the baskets equal or -1 if impossible.

    Example :

    Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
    Output: 1
    Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
"""


from collections import Counter
from typing import List

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        count1 = Counter(basket1)
        count2 = Counter(basket2)
        minX = min(basket1 + basket2)

        for key in count1.keys():
            while count1[key] > 0 and count2[key] > 0:
                min_count = min(count1[key], count2[key])
                count1[key] -= min_count
                count2[key] -= min_count
        for val in list(count1.values()) + list(count2.values()):
            if val % 2 == 1:
                return -1
        
        swap1 = []
        for key in count1.keys():
            swap1.extend([key] * (count1[key] // 2))

        swap2 = []
        for key in count2.keys():
            swap2.extend([key] * (count2[key] // 2))
            
        swap1, swap2 = sorted(swap1), sorted(swap2)[::-1]

        res = 0
        for i in range(len(swap1)):
            res += min(swap1[i], swap2[i], minX * 2)

        return res