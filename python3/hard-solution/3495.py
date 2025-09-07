"""
3495. Minimum Operations to Make Array Elements Zero 
    You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.
    In one operation, you can:
    Select two integers a and b from the array.
    Replace them with floor(a / 4) and floor(b / 4).
    Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

    Example :
    Input: queries = [[1,2],[2,4]]
    Output: 3
    Explanation:
    For queries[0]:
    The initial array is nums = [1, 2].
    In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
    The minimum number of operations required is 1.
    For queries[1]:

    The initial array is nums = [2, 3, 4].
    In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
    In the second operation, select nums[1] and nums[2]. The array becomes [0, 0, 0].
    The minimum number of operations required is 2.
    The output is 1 + 2 = 3.
"""


from bisect import bisect_right
from typing import List

class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        pow4 = [1]
        while pow4[-1] <= 10 ** 9:
            pow4.append(pow4[-1] * 4)
        prefix = [0]
        for i in range(len(pow4) - 1):
            prefix.append(prefix[-1] + (i + 1) * 3 * pow4[i])

        def F(n : int) -> int:
            if n <= 0:
                return 0
            k = bisect_right(pow4, n) - 1
            return prefix[k] + (k + 1) * (n - pow4[k] + 1)
        res = 0
        for l, r in queries:
            s = F(r) - F(l - 1)
            res += (s + 1) // 2
        return res