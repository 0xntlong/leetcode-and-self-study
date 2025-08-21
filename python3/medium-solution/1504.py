"""
1504. Count Submatrices With All Ones
    Given an m x n binary matrix mat, return the number of submatrices that have all ones.

    Example :
    Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
    Output: 13
    Explanation: 
    There are 6 rectangles of side 1x1.
    There are 2 rectangles of side 1x2.
    There are 3 rectangles of side 2x1.
    There is 1 rectangle of side 2x2. 
    There is 1 rectangle of side 3x1.
    Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
"""

from typing import List

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        height = [0] * n
        res = 0
        for i in range(m):
            for j in range(n):
                height[j] = height[j] + 1 if mat[i][j] == 1 else 0
            stack = []
            cur = 0
            for h in height:
                cnt = 1
                while stack and stack[-1][0] >= h:
                    ph, pc = stack.pop()
                    cur -= ph * pc
                    cnt += pc
                cur += h * cnt
                stack.append((h, cnt))
                res += cur
        return res