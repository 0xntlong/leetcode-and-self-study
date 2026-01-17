"""
3047. Find the Largest Area of Square Inside Two Rectangles
    There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.
    You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.
    Example :
    Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
    Output: 1
    Explanation:
    A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.
"""
from typing import List

class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        maxSquare = 0
        for i in range(n - 1):
            a, b = bottomLeft[i]
            c, d = topRight[i]
            for j in range(i + 1, n):
                aj, bj = bottomLeft[j]
                cj, dj = topRight[j]
                width = min(c, cj) - max(a, aj)
                height = min(d, dj) - max(b, bj)
                if width > 0 and height > 0:
                    square = min(width, height)
                    if square > maxSquare:
                        maxSquare = square
        return maxSquare ** 2