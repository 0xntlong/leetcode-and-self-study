"""
3464. Maximize the Distance Between Points on a Square
    You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.
    You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.
    You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.
    Return the maximum possible minimum Manhattan distance between the selected k points.
    The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
    
    Example 1:
    Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4
    Output: 2

"""

from typing import List
from bisect import bisect_left

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        res = []
        for x, y in points:
            if x == 0:
                res.append(y)
            elif y == side:
                res.append(side + x)
            elif x == side:
                res.append(side * 3 - y)
            else:
                res.append(side * 4 - x)
        res.sort()
        def check(n : int) -> bool:
            idx = [0] * k
            curr = res[0]
            for i in range(1, k):
                j = bisect_left(res, curr + n)
                if j == len(res):
                    return False
                idx[i] = j
                curr = res[j]
            if curr - res[0] <= side * 4 - n:
                return True
            
            for idx[0] in range(1, idx[1]):
                for j in range(1, k):
                    while res[idx[j]] < res[idx[j - 1]] + n:
                        idx[j] += 1
                        if idx[j] == len(res):
                            return False
                if res[idx[-1]] - res[idx[0]] <= side * 4 - n:
                    return True
            return False
        
        left, right = 1, side + 1
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                left = mid
            else:
                right = mid
        return left 