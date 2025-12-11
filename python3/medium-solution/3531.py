"""
3531. Count Covered Buildings
    You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
    A building is covered if there is at least one building in all four directions: left, right, above, and below.
    Return the number of covered buildings.

    Example :
    Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    Output: 1
    Explanation:
    Only building [2,2] is covered as it has at least one building:
    above ([1,2])
    below ([3,2])
    left ([2,1])
    right ([2,3])
    Thus, the count of covered buildings is 1.
"""

from collections import defaultdict
from typing import List


class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        dict_x = defaultdict(list)
        dict_y = defaultdict(list)

        for x, y in buildings:
            dict_x[x].append(y)
            dict_y[y].append(x)
        for x in dict_x:
            dict_x[x].sort()
        for y in dict_y:
            dict_y[y].sort()
        res = 0
        for x, y in buildings:
            ox = dict_x[x]
            oy = dict_y[y]
            if oy[0] < x < oy[-1] and ox[0] < y < ox[-1]:
                res += 1
        return res