"""
1840. Maximum Building Height
    You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
    However, there are city restrictions on the heights of the new buildings:
    The height of each building must be a non-negative integer.
    The height of the first building must be 0.
    The height difference between any two adjacent buildings cannot exceed 1.
    Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
    It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
    Return the maximum possible height of the tallest building.

    Example :
    Input: n = 5, restrictions = [[2,1],[4,1]]
    Output: 2
    Explanation: The green area in the image indicates the maximum allowed height for each building.
    We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
"""

from typing import List

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        if not restrictions:
            return n - 1
        restrictions.sort()
        idx, h = 1, 0
        for i in range(len(restrictions)):
            x, y = restrictions[i]
            restrictions[i][1] = min(y, x - idx + h)
            idx, h = x, restrictions[i][1]

        for i in range(len(restrictions) - 2, -1, -1):
            restrictions[i][1] = min(restrictions[i][1], 
                                restrictions[i+1][1] + 
                                restrictions[i + 1][0] - 
                                restrictions[i][0])

        res = n - restrictions[-1][0] + restrictions[-1][1]
        idx, h = 1, 0
        for x, y in restrictions:
            steps = x - idx - abs(y - h)
            higher = max(y, h)
            res = max(res, higher + steps // 2)
            idx, h = x, y
        return res