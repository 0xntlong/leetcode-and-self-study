"""
1975. Maximum Matrix Sum
    You are given an n x n integer matrix. You can do the following operation any number of times:
    Choose any two adjacent elements of matrix and multiply each of them by -1.
    Two elements are considered adjacent if and only if they share a border.
    Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

    Example :
    Input: matrix = [[1,-1],[-1,1]]
    Output: 4
    Explanation: We can follow the following steps to reach sum equals 4:
    - Multiply the 2 elements in the first row by -1.
    - Multiply the 2 elements in the first column by -1.
"""

from typing import List
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        res = 0
        min_matrix = float('inf')
        neg_cnt = 0
        for row in matrix:
            for r in row:
                min_matrix = min(min_matrix, abs(r))
                if r < 0:
                    res -= r
                    neg_cnt += 1
                else:
                    res += r
        return (res - 2 * min_matrix) if (neg_cnt & 1) else res
    
    """
    total = 0
        cnt = 0
        mini = inf
        for i in matrix:
            for x in i:
                if x < 0:
                    cnt += 1
                    x = -x
                if x < mini:
                    mini = x
                total += x
        if cnt % 2 == 0:
            return total
        else:
            return total - mini * 2
    """