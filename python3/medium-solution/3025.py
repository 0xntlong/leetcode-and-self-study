"""
3025. Find the Number of Ways to Place People I
    You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].
    Count the number of pairs of points (A, B), where
    A is on the upper left side of B, and
    there are no other points in the rectangle (or line) they make (including the border).
    Return the count.

    Example:
    Input: points = [[1,1],[2,2],[3,3]]
    Output: 0
    Explanation:
    There is no way to choose A and B so A is on the upper left side of B.
"""

from typing import List
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x : (-x[0], x[1]))
        n = len(points)
        res = 0
        for i in range(n - 1):
            y = 1 << 31
            for j in range(i + 1, n):
                if y > points[j][1] >= points[i][1]:
                    res += 1
                    y = points[j][1]
        return res