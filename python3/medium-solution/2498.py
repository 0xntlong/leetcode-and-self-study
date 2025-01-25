"""
2948. Make Lexicographically Smallest Array by Swapping Elements
    You are given a 0-indexed array of positive integers nums and a positive integer limit.
    In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
    Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
    An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

    Example :
    Input: nums = [1,5,3,9,8], limit = 2
    Output: [1,3,5,8,9]
    Explanation: Apply the operation 2 times:
    - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
    - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
    We cannot obtain a lexicographically smaller array by applying any more operations.
    Note that it may be possible to get the same result by doing different operations.
"""

from typing import List
class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        idx = list(range(n))

        idx.sort(key=lambda i : nums[i])

        group = [[idx[0]]]
        prev = nums[idx[0]]

        for i in range(1, n):
            I = idx[i]
            x = nums[I]
            if x - prev <= limit:
                group[-1].append(I)
            else:
                group.append([I])
            prev = x

        for seq in group:
            values = [nums[index] for index in seq]
            values.sort()
            seq.sort()
            for i in range(len(seq)):
                nums[seq[i]] = values[i]

        return nums