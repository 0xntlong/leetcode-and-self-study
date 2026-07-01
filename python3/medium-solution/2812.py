"""
2812. Find the Safest Path in a Grid
    You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
    A cell containing a thief if grid[r][c] = 1
    An empty cell if grid[r][c] = 0
    You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
    The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
    Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
    An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
    The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
    Example :
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 0
    Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
"""



from ast import List
from collections import deque
import heapq

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if grid[0][0] == 1 or grid[n - 1][n - 1] == 1:
            return 0

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        dist = [[float("inf")] * n for _ in range(n)]
        q = deque()

        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    dist[r][c] = 0
                    q.append((r, c))

        while q:
            r, c = q.popleft()

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n and dist[nr][nc] == float("inf"):
                    dist[nr][nc] = dist[r][c] + 1
                    q.append((nr, nc))

        seen = [[False] * n for _ in range(n)]

        heap = [(-dist[0][0], 0, 0)]

        while heap:
            neg_safe, r, c = heapq.heappop(heap)
            safe = -neg_safe

            if seen[r][c]:
                continue

            seen[r][c] = True

            if r == n - 1 and c == n - 1:
                return safe

            for dr, dc in dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n and not seen[nr][nc]:
                    new_safe = min(safe, dist[nr][nc])
                    heapq.heappush(heap, (-new_safe, nr, nc))

        return -1