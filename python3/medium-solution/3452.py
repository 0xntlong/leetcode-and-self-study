"""
3453. Separate Squares I
    You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
    Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.
    Answers within 10-5 of the actual answer will be accepted.
    Note: Squares may overlap. Overlapping areas should be counted multiple times.

    Example :
    Input: squares = [[0,0,1],[2,2,1]]
    Output: 1.00000
    Explanation:
    Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.
"""

from typing import List
from collections import defaultdict
from itertools import pairwise


class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        total = 0
        diff = defaultdict(int)
        for _, y, s in squares:
            total += s * s
            diff[y] += s
            diff[y + s] -= s
        area = 0
        target = 0
        for y, y2 in pairwise(sorted(diff)):
            target += diff[y]
            area += target * (y2 - y)
            if area * 2 >= total:
                return y2 - (area * 2 - total) / (target * 2)