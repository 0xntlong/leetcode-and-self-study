"""
1637. Widest Vertical Area Between Two Points Containing No Points
    Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
    A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
    Note that points on the edge of a vertical area are not considered included in the area.


    Example :
    Input: points = [[8,7],[9,9],[7,4],[9,7]]
    Output: 1
    Explanation: Both the red and the blue area are optimal.
"""

from typing import List
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x = sorted(point[0] for point in points)
        Max = 0
        for i in range(1, len(x)):
            wid = x[i] - x[i - 1]
            Max = max(Max, wid)
        return Max