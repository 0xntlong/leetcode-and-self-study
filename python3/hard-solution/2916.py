"""
2916. Subarrays Distinct Element Sum of Squares II
    You are given a 0-indexed integer array nums.
    The distinct count of a subarray of nums is defined as:
    Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
    Return the sum of the squares of distinct counts of all subarrays of nums.
    Since the answer may be very large, return it modulo 109 + 7.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,2,1]
    Output: 15
    Explanation: Six possible subarrays are:
    [1]: 1 distinct value
    [2]: 1 distinct value
    [1]: 1 distinct value
    [1,2]: 2 distinct values
    [2,1]: 2 distinct values
    [1,2,1]: 2 distinct values
    The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
"""



class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        bit1 = [0] * (n + 1)
        bit2 = [0] * (n + 1)
        last = [-1] * 100001

        def prefix_sum(k: int) -> int:
            s1 = s2 = 0
            index = k
            while index > 0:
                s1 += bit1[index]
                s2 += bit2[index]
                index -= index & -index
            return k * s1 - s2

        def add_boundary(index: int, delta: int) -> None:
            weighted = delta * (index - 1)
            while index <= n:
                bit1[index] += delta
                bit2[index] += weighted
                index += index & -index

        total_distinct = 0
        ending_squares = 0
        answer = 0

        for i, value in enumerate(nums):
            p = last[value]
            
            affected_sum = total_distinct - prefix_sum(p + 1)
            length = i - p
            ending_squares = (ending_squares + 2 * affected_sum + length) % MOD
            answer = (answer + ending_squares) % MOD

            add_boundary(p + 2, 1)
            add_boundary(i + 2, -1)
            total_distinct += length
            last[value] = i

        return answer