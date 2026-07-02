"""
3286. Find a Safe Walk Through a Grid
    You are given an m x n binary matrix grid and an integer health.
    You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
    You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
    Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
    Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

    Example :
    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
    Output: true
    Explanation:
    The final cell can be reached safely by walking along the gray cells below.
"""


from collections import deque
from typing import List


class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        row=len(grid)
        col=len(grid[0])
        dist=[[-2] * col for _ in range(row)]
        q=deque([(0,0)])
        if grid[0][0] == 1:
            dist[0][0]= health-1
            if dist[0][0] <= 0:
                return False
        else:
            dist[0][0] = health
    
        while q:
            i ,j = q.popleft()
            if i == row - 1 and j == col - 1:
                return True
            for x, y in (i - 1, j),(i + 1, j),(i, j - 1),(i, j+1):

                if x >= 0 and x < row and y < col and y >= 0 and dist[x][y]== -2:
                    if grid[x][y]==1 :
                        cost=1
                    else:
                        cost=0
                    new_health = dist[i][j]-cost
                    
                    if new_health > 0 and new_health > dist[x][y]:
                        dist[x][y] = new_health
            
                        if cost == 0:
                            q.appendleft((x, y))
                        else:
                            q.append((x, y))

        return False