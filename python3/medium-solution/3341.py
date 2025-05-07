"""
3341. Find Minimum Time to Reach Last Room I
    There is a dungeon with n x m rooms arranged as a grid.
    You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
    Return the minimum time to reach the room (n - 1, m - 1).
    Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example :
    Input: moveTime = [[0,4],[4,4]]
    Output: 6
    Explanation:
    The minimum time required is 6 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in one second.
"""

from typing import List

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        rows = len(moveTime)
        cols = len(moveTime[0])

        if rows == 1 and cols == 1:
            return 0

        visited = set()
        visited.add((0, 0))
        
        h = [(0, 0, 0)]
        while h:
            ways = [(-1, 0), (0, -1), (0, 1), (1, 0)]
            time, row, col = heappop(h)
            if (row, col) == (rows - 1, cols - 1):
                return time
            for dx, dy in ways:
                nextRow, nextCol = row + dx, col + dy
                if 0 <= nextRow < rows and 0 <= nextCol < cols and (nextRow, nextCol) not in visited:
                    heappush(h, (max(time, moveTime[nextRow][nextCol]) + 1, nextRow, nextCol))
                    visited.add((nextRow, nextCol))
        return -1
