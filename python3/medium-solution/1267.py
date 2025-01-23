"""
1267. Count Servers that Communicate
    You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
    Return the number of servers that communicate with any other server.
    Example :
    Input: grid = [[1,0],[0,1]]
    Output: 0
    Explanation: No servers can communicate with others.
"""

from typing import List
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        m , n = len(grid), len(grid[0])
        row = [0] * m
        col = [0] * n

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    row[i] += 1
                    col[j] += 1
        
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if row[i] > 1 or col[j] > 1:
                        count += 1
        
        return count