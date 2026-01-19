"""
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

    Example :
    Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
    Output: 2
    Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

"""
from typing import List


class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)
        n = len(mat[0])
        prefix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                prefix[i+1][j+1] = (mat[i][j] 
                                    + prefix[i][j+1] 
                                    + prefix[i+1][j] 
                                    - prefix[i][j])
        left = 1
        right = min(m, n)
        res = 0
        while left <= right:
            mid = (left + right) // 2
            isValid = False
            for i in range(mid, m + 1):
                for j in range(mid, n + 1):
                    square_sum = (prefix[i][j] 
                                - prefix[i-mid][j] 
                                - prefix[i][j-mid] 
                                + prefix[i-mid][j-mid])
                    if square_sum <= threshold:
                        isValid = True
                        break
                if isValid:
                    break
            if isValid:
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res