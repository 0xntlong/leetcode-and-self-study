"""
1072. Flip Columns For Maximum Number of Equal Rows
    You are given an m x n binary matrix matrix.
    You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
    Return the maximum number of rows that have all values equal after some number of flips.

    Example :
    Input: matrix = [[0,1],[1,1]]
    Output: 1
    Explanation: After flipping no values, 1 row has all values equal.
"""
from collections import Counter
from typing import List
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        count = Counter()
        for r in matrix:
            t = tuple(r) if r[0] == 0 else tuple(x ^ 1 for x in r)
            count[t] += 1
        return max(count.values())