"""
3342. Find Minimum Time to Reach Last Room II
    There is a dungeon with n x m rooms arranged as a grid.
    You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
    Return the minimum time to reach the room (n - 1, m - 1).
    Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example :
    Input: moveTime = [[0,4],[4,4]]
    Output: 7
    Explanation:
    The minimum time required is 7 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
"""

from typing import List
import heapq


class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])
        INF = float('inf')
        dp = [[INF] * m for _ in range(n)]
        heap = [(0, 0 , 0)]
        moveTime[0][0] = 0
        ways = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        while heap:
            time, row, col = heapq.heappop(heap)
            if time >= dp[row][col]:
                continue
            if row == n - 1 and col == m - 1:
                return time
            dp[row][col] = time
            for x, y in ways:
                nextRow = row + x
                nextCol = col + y
                if 0 <= nextRow < n and 0 <= nextCol < m and dp[nextRow][nextCol] == INF:
                    cost = (row + col) % 2 + 1
                    count = max(moveTime[nextRow][nextCol], time)
                    nextTime = count + cost
                    heapq.heappush(heap, (nextTime, nextRow, nextCol))
        return -1