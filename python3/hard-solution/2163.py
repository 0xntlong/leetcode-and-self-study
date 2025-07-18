"""
2163. Minimum Difference in Sums After Removal of Elements
    You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

    The first n elements belonging to the first part and their sum is sumfirst.
    The next n elements belonging to the second part and their sum is sumsecond.
    The difference in sums of the two parts is denoted as sumfirst - sumsecond.

    For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
    Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
    Return the minimum difference possible between the sums of the two parts after the removal of n elements.

    Example :

    Input: nums = [3,1,2]
    Output: -1
    Explanation: Here, nums has 3 elements, so n = 1. 
    Thus we have to remove 1 element from nums and divide the array into two equal parts.
    - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
    - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
    - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
    The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
"""

from typing import List
from heapq import heapify, heappush, heappop, heapreplace


class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) // 3
        max_heap = [-x for x in nums[:n]]
        heapify(max_heap)
        left_sum = sum(nums[:n])
        left_diff = [0] * (n + 1)
        left_diff[0] = left_sum

        for i in range(n, 2 * n):
            num = nums[i]
            if num < -max_heap[0]:
                left_sum += num + max_heap[0]
                heapreplace(max_heap, -num)
            left_diff[i - n + 1] = left_sum

        min_heap = nums[2 * n:]
        heapify(min_heap)
        right_sum = sum(min_heap)
        min_diff = left_diff[-1] - right_sum
        for i in range(2 * n - 1, n - 1, -1):
            num = nums[i]
            if num > min_heap[0]:
                right_sum += num - min_heap[0]
                heapreplace(min_heap, num)
            diff_index = i - n
            curr_diff = left_diff[diff_index] - right_sum
            min_diff = min(min_diff, curr_diff)
        return min_diff