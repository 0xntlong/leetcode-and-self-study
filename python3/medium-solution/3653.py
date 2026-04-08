"""
3653. XOR After Range Multiplication Queries I
    You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

    For each query, you must apply the following operations in order:
    Set idx = li.
    While idx <= ri:
    Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
    Set idx += ki.
    Return the bitwise XOR of all elements in nums after processing all queries.
    Example :
    Input: nums = [1,1,1], queries = [[0,2,1,4]]

    Output: 4

    Explanation:

    A single query [0, 2, 1, 4] multiplies every element from index 0 through index 2 by 4.
    The array changes from [1, 1, 1] to [4, 4, 4].
    The XOR of all elements is 4 ^ 4 ^ 4 = 4.
"""


from ast import List
class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = 10**9 + 7
        for l, r, k, v in queries:
            for idx in range(l, r + 1, k):
                nums[idx] = (nums[idx] * v) % mod
        res = 0
        for i in nums:
            res ^= i
        return res