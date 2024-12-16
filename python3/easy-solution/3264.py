"""
3264. Final Array State After K Multiplication Operations I
    You are given an integer array nums, an integer k, and an integer multiplier.
    You need to perform k operations on nums. In each operation:
    Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
    Replace the selected minimum value x with x * multiplier.
    Return an integer array denoting the final state of nums after performing all k operations.

    Example :
    Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
    Output: [8,4,6,5,6]
    Explanation:
    Operation	Result
    After operation 1	[2, 2, 3, 5, 6]
    After operation 2	[4, 2, 3, 5, 6]
    After operation 3	[4, 4, 3, 5, 6]
    After operation 4	[4, 4, 6, 5, 6]
    After operation 5	[8, 4, 6, 5, 6]
"""


from typing import List
# APPROACH 1:
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            idx = nums.index(min(nums))
            nums[idx] *= multiplier
        return nums
    

# APPROACH 2:
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        ans = [0] * len(nums)
        minHeap = [(num, idx) for idx, num in enumerate(nums)]
        heapq.heapify(minHeap)
        for _ in range(k):
            num, idx = heapq.heappop(minHeap)
            heapq.heappush(minHeap, (num * multiplier, idx))
        for num, idx in minHeap:
            ans[idx] = num
        return ans