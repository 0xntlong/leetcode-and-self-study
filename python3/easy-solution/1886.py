"""
1886. Determine Whether Matrix Can Be Obtained By Rotation
    Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
    
    Example :
    Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
    Output: true
    Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
"""

from typing import List
class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        if mat == target:
            return True
        n = len(mat)
        count = 3
        while count:
            for i in range(n):
                for j in range(i, n):
                    mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
            for i in range(n):
                mat[i].reverse()
            if mat == target:
                return True
            count -= 1
        return False