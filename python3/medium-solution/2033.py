"""
2033. Minimum Operations to Make a Uni-Value Grid
    You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
    A uni-value grid is a grid where all the elements of it are equal.
    Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

    Example :
    Input: grid = [[2,4],[6,8]], x = 2
    Output: 4
    Explanation: We can make every element equal to 4 by doing the following: 
    - Add x to 2 once.
    - Subtract x from 6 once.
    - Subtract x from 8 twice.
    A total of 4 operations were used.
"""

from typing import List
from collections import Counter
from math import inf

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        count = Counter(n for arr in grid for n in arr)

        for i in count:
            if (grid[0][0] - i) % x:
                return -1

        arr, prev, curr, minC, maxC = [], 0, 0, min(count), max(count)
        
        for n in range(minC, maxC + 1, x):
            arr.append(prev + curr)
            prev, curr = arr[-1], curr + count[n]

        res, curr, nxt = inf, 0, 0

        for n in range(maxC, minC - 1, -x):
            res = min(res, arr.pop() + curr + nxt)
            curr, nxt = curr + count[n], curr + nxt
        return res