"""
2492. Minimum Score of a Path Between Two Cities
    You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

    The score of a path between two cities is defined as the minimum distance of a road in this path.

    Return the minimum possible score of a path between cities 1 and n.

    Note:

    A path is a sequence of roads between two cities.
    It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    The test cases are generated such that there is at least one path between 1 and n.

    Example :
    Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    Output: 5
    Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
    It can be shown that no other path has less score.
"""
from typing import List

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        root = list(range(n + 1))
        def find(i: int) -> int:
            if root[i] != i:
                root[i] = find(root[i])
            return root[i]
        for x, y, d in roads:
            root[find(x)] = find(y)
        res = 10**9
        g1 = find(1)
        for x, y, d in roads:
            if find(x) == g1:
                res = min(res, d)
        return res