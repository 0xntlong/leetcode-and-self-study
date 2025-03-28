"""
3394. Check if Grid can be Cut into Sections
    You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
    (startx, starty): The bottom-left corner of the rectangle.
    (endx, endy): The top-right corner of the rectangle.
    Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
    Each of the three resulting sections formed by the cuts contains at least one rectangle.
    Every rectangle belongs to exactly one section.
    Return true if such cuts can be made; otherwise, return false.
    Example :
    Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    Output: true
"""
from typing import List

class Solution:
    def check(self, a, n):
        temp = [a[0]]
        for i in range(1, n):
            if a[i][0] >= temp[-1][1]:
                temp.append(a[i])
            else:
                temp[-1] = (temp[-1][0], max(temp[-1][1], a[i][1]))
        return len(temp) >= 3

    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        m = len(rectangles)
        x, y = [], []
        for i in rectangles:
            x.append((i[0], i[2]))
            y.append((i[1], i[3]))
        x.sort()
        y.sort()

        return self.check(x, m) or self.check(y, m)