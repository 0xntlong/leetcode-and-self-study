"""
118. Pascal's Triangle
    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example :
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
"""

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        temp = [[]] * numRows
        for i in range(numRows):
            temp[i] = [1] * (i + 1)
            for j in range(1, i // 2 + 1):
                temp[i][i - j] = temp[i][j] = temp[i - 1][j - 1] + temp[i - 1][j]
        return temp
