"""
3625. Count Number of Trapezoids II
    You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
    Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
    A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

    Example 1:
    Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
    Output: 2
    Explanation:
    There are two distinct ways to pick four points that form a trapezoid:

    The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
    The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
"""

from typing import List
from collections import Counter
from math import gcd
from itertools import combinations
from math import comb

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        slopes = Counter()
        lines = Counter()
        mids = Counter()
        midlines = Counter()
        for(x1, y1), (x2, y2) in combinations(points, 2):
            dx, dy = x1 - x2, y1 - y2
            g = gcd(dx, dy)
            dx = dx // g
            dy = dy // g
            if dx < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            inter = x1 * dy - y1 * dx
            slopes[dx, dy] += 1
            lines[dx, dy, inter] += 1
            mids[x1 + x2, y1 + y2] += 1
            midlines[x1 + x2, y1 + y2, dx, dy, inter] += 1
        res = sum(comb(v, 2) for v in slopes.values())
        res -= sum(comb(v, 2) for v in lines.values())
        res -= sum(comb(v, 2) for v in mids.values())
        res += sum(comb(v, 2) for v in midlines.values())
        return res