"""
3691. Maximum Total Subarray Value II
    You are given an integer array nums of length n and an integer k.
    You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.
    The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
    The total value is the sum of the values of all chosen subarrays.
    Return the maximum possible total value you can achieve.

    Example :
    Input: nums = [1,3,2], k = 2
    Output: 4
    Explanation:
    One optimal approach is:
    Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
    Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
    Adding these gives 2 + 2 = 4.
"""


from typing import List


class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        size = 1
        while size < n:
            size *= 2
        seg_max = [0] * (2 * size)
        seg_min = [10**18] * (2 * size)
        for i in range(n):
            seg_max[size + i] = nums[i]
            seg_min[size + i] = nums[i]
        for i in range(size - 1, 0, -1):
            seg_max[i] = max(seg_max[2 * i], seg_max[2 * i + 1])
            seg_min[i] = min(seg_min[2 * i], seg_min[2 * i + 1])
        def query(l, r):
            l += size
            r += size
            mx = 0
            mn = 10**18
            while l <= r:
                if l % 2 == 1:
                    mx = max(mx, seg_max[l])
                    mn = min(mn, seg_min[l])
                    l += 1
                if r % 2 == 0:
                    mx = max(mx, seg_max[r])
                    mn = min(mn, seg_min[r])
                    r -= 1
                l //= 2
                r //= 2
            return mx - mn
        heap = []
        for l in range(n):
            val = query(l, n - 1)
            heapq.heappush(heap, (-val, l, n - 1))
        ans = 0
        for _ in range(k):
            val, l, r = heapq.heappop(heap)
            ans += -val
            if r > l:
                new_val = query(l, r - 1)
                heapq.heappush(heap, (-new_val, l, r - 1))
        return ans