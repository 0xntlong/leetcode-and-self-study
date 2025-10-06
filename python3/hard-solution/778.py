"""
778. Swim in Rising Water
    You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
    It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.
    You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
    Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

    Example :
    Input: grid = [[0,2],[1,3]]
    Output: 3
    Explanation:
    At time 0, you are in grid location (0, 0).
    You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
    You cannot reach point (1, 1) until time 3.
    When the depth of water is 3, we can swim anywhere inside the grid.
"""


from typing import List
import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        heap = []
        visited = set((0, 0))
        heap.append((grid[0][0], 0, 0))
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while heap:
            curr, r, c = heapq.heappop(heap)
            if r == n - 1 and c == n - 1:
                return curr
            for dr, dc in dirs:
                nr, nc = dr + r, dc + c
                if 0 <= nr < n and 0 <= nc < n and (nr, nc) not in visited:
                    heapq.heappush(heap, (max(curr, grid[nr][nc]), nr, nc))
                    visited.add((nr, nc))