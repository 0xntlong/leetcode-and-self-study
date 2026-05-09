"""
1914. Cyclically Rotating a Grid
    You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
    The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
    A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
    Return the matrix after applying k cyclic rotations to it.

    Example :
    Input: grid = [[40,10],[30,20]], k = 1
    Output: [[10,20],[40,30]]
    Explanation: The figures above represent the grid at every state.
"""

from typing import List

class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        for layer in range(min(m, n) // 2):
            r, c, val = [], [], []
            for i in range(layer, m - layer - 1):
                r.append(i)
                c.append(layer)
                val.append(grid[i][layer])
            for j in range(layer, n - layer - 1):  
                r.append(m - layer - 1)
                c.append(j)
                val.append(grid[m-layer-1][j])
            for i in range(m - layer - 1, layer, -1): 
                r.append(i)
                c.append(n - layer - 1)
                val.append(grid[i][n-layer-1])
            for j in range(n - layer - 1, layer, -1):  
                r.append(layer)
                c.append(j)
                val.append(grid[layer][j])
            total = len(val)  
            kk = k % total   
            for i in range(total):
                idx = (i + total - kk) % total  
                grid[r[i]][c[i]] = val[idx]
        return grid