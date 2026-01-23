"""
3510. Minimum Pair Removal to Sort Array II
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

    Example :
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.

"""
from typing import List
from math import inf
from heapq import heappop, heappush, heapify
from itertools import pairwise


class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        nums.append(inf)

        left = [-1] * (n + 1)
        right = [i + 1 for i in range(n + 1)]
        for i in range(1, n + 1):
            left[i] = i - 1

        heap = [(a + b, i) for i, (a, b) in enumerate(pairwise(nums))]
        heapify(heap)

        rest = sum(1 for a, b in pairwise(nums) if a > b)
        ans = 0

        while rest > 0:
            v, i = heappop(heap)
            r = right[i]

            if r == -1 or nums[i] + nums[r] != v or left[r] != i:
                continue

            rr = right[r]

            if left[i] != -1 and nums[left[i]] > nums[i]:
                rest -= 1
            if nums[i] > nums[r]:
                rest -= 1
            if rr != -1 and nums[r] > nums[rr]:
                rest -= 1

            nums[i] = v
            right[i] = rr
            if rr != -1:
                left[rr] = i

            if left[i] != -1 and nums[left[i]] > nums[i]:
                rest += 1
            if rr != -1 and nums[i] > nums[rr]:
                rest += 1

            if left[i] != -1:
                heappush(heap, (nums[left[i]] + nums[i], left[i]))
            if rr != -1:
                heappush(heap, (nums[i] + nums[rr], i))

            ans += 1

        return ans