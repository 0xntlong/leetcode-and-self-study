"""
3514. Number of Unique XOR Triplets II
    You are given an integer array nums.
    A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.
    Return the number of unique XOR triplet values from all possible triplets (i, j, k).
    Example :
    Input: nums = [1,3]
    Output: 2
    Explanation:
    The possible XOR triplet values are:
    (0, 0, 0) → 1 XOR 1 XOR 1 = 1
    (0, 0, 1) → 1 XOR 1 XOR 3 = 3
    (0, 1, 1) → 1 XOR 3 XOR 3 = 1
    (1, 1, 1) → 3 XOR 3 XOR 3 = 3
    The unique XOR values are {1, 3}. Thus, the output is 2.
"""



from ast import List


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        m = max(nums)

        size = 1
        while size <= m:
            size <<= 1

        one = [False] * size
        two = [False] * size
        three = [False] * size

        for x in nums:
            one[x] = True

            for y in range(size):
                if one[y]:
                    two[y ^ x] = True

        for x in nums:
            for y in range(size):
                if two[y]:
                    three[y ^ x] = True

        return sum(three)