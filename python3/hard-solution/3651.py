"""
3651. Minimum Cost Path with Teleportations
    You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).
    There are two types of moves available:
    Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
    Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.
    Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).
    Example :
    Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
    Output: 7
    Explanation:
    Initially we are at (0, 0) and cost is 0.
    Current Position	Move	New Position	Total Cost
    (0, 0)	Move Down	(1, 0)	0 + 2 = 2
    (1, 0)	Move Right	(1, 1)	2 + 5 = 7
    (1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
    The minimum cost to reach bottom-right cell is 7.
"""
from typing import List 

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        INF = 10**30
        cells = []
        for i in range(m):
            for j in range(n):
                idx = i * n + j
                cells.append((grid[i][j], idx))
        cells.sort(reverse=True)
        dist = [INF] * (m * n)
        dist[0] = 0
        best = INF
        for t in range(k + 1):
            for i in range(m):
                for j in range(n):
                    idx = i * n + j
                    cur = dist[idx]
                    if cur == INF:
                        continue
                    if j + 1 < n:
                        ni = idx + 1
                        cost = cur + grid[i][j + 1]
                        if cost < dist[ni]:
                            dist[ni] = cost
                    if i + 1 < m:
                        ni = idx + n
                        cost = cur + grid[i + 1][j]
                        if cost < dist[ni]:
                            dist[ni] = cost
            best = min(best, dist[m * n - 1])
            if t == k:
                break
            nextDist = [INF] * (m * n)
            move = INF
            p = 0
            while p < len(cells):
                val = cells[p][0]
                q = p
                group_min = INF
                while q < len(cells) and cells[q][0] == val:
                    group_min = min(group_min, dist[cells[q][1]])
                    q += 1
                move = min(move, group_min)
                for t2 in range(p, q):
                    idx = cells[t2][1]
                    nextDist[idx] = move
                p = q
            dist = nextDist
        return best if best < INF else -1