"""
2294. Partition Array Such That Maximum Difference Is K
    You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
    Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [3,6,1,2,5], k = 2
    Output: 2
    Explanation:
    We can partition nums into the two subsequences [3,1,2] and [6,5].
    The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
    The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
    Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
"""


from typing import List
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        if k == 0:
            return len(set(nums))
        nums = sorted(list(set(nums)))
        res = 0
        prev = -1
        for num in nums:
            if num > prev:
                prev = num
                res += 1
                prev += k
            else:
                continue
        return res