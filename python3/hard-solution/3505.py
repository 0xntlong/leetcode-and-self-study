"""
3505. Minimum Operations to Make Elements Within K Subarrays Equal
    You are given an integer array nums and two integers, x and k. You can perform the following operation any number of times (including zero):
    Increase or decrease any element of nums by 1.
    Return the minimum number of operations needed to have at least k non-overlapping subarrays of size exactly x in nums, where all elements within each subarray are equal.
    Example :
    Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
    Output: 8
    Explanation:
    Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
    Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
    Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.
"""

from ast import List


class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)
        left, right = SortedList(), SortedList()
        sum_l = sum_r = 0
        ops = [0] * n

        for i, value in enumerate(nums):
            if not left or value <= left[-1]:
                left.add(value)
                sum_l += value
            else:
                right.add(value)
                sum_r += value
            if i >= x:
                value = nums[i - x]
                if value in left:
                    left.remove(value)
                    sum_l -= value
                else:
                    right.remove(value)
                    sum_r -= value
            if len(left) > len(right) + 1:
                value = left.pop()
                right.add(value)
                sum_l -= value
                sum_r += value
            elif len(left) < len(right):
                value = right.pop(0)
                left.add(value)
                sum_l += value
                sum_r -= value
            if i >= x - 1:
                mid = left[-1]
                ops[i] = mid * len(left) - sum_l + sum_r - mid * len(right)

        pre = [0] * (n + 1)
        cur = [inf] * (n + 1)
        for j in range(1, k + 1):
            for i in range(n + 1):
                cur[i] = inf
            for i in range(j * x, n + 1):
                cur[i] = min(cur[i - 1], pre[i - x] + ops[i - 1])
            pre, cur = cur, pre
        return pre[n]