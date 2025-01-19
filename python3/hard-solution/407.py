"""
407. Trapping Rain Water II
    Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
    
    Example :
    Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.
"""

from typing import List
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m = len(heightMap)
        n = len(heightMap[0])

        vol = [[heightMap[i][j] for j in range(n)] for i in range(m)]

        upt, init = True, True

        while upt:
            upt = False
            for i in range(1, m - 1):
                for j in range(1, n -1):
                    val = max(heightMap[i][j], min(vol[i - 1][j], vol[i][j - 1]))
                    if init or vol[i][j] > val:
                        vol[i][j] = val
                        upt = True
            init = False
            for i in range(m - 2, 0, -1):
                for j in range(n - 2, 0, -1):
                    val = max(heightMap[i][j], min(vol[i + 1][j], vol[i][j + 1]))
                    if vol[i][j] > val:
                        vol[i][j] = val
                        upt = True
        res = 0

        for i in range(1, m - 1):
            for j in range(1, n - 1):
                if vol[i][j] > heightMap[i][j]:
                    res += vol[i][j] - heightMap[i][j]
        
        return res