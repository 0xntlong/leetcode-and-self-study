"""
976. Largest Perimeter Triangle
    Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
    Example :
    Input: nums = [2,1,2]
    Output: 5
    Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
"""



from typing import List
import heapq
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        """
        nums = sorted(nums, reverse = True)
        for i in range(len(nums) - 2):
            a = nums[ i + 2]
            b = nums[ i + 1]
            c = nums[i]
            if a + b > c:
                return a + b + c
        return 0
        """
        nums = [-num for num in nums]
        heapq.heapify(nums)
        while len(nums) >= 3:
            a = -heapq.heappop(nums)
            b = -heapq.heappop(nums)
            c = -nums[0]
            if b + c > a:
                return a + b + c
            heapq.heappush(nums, -b)
        return 0