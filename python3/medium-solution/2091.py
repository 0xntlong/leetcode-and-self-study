"""
2091. Removing Minimum and Maximum From Array
    You are given a 0-indexed array of distinct integers nums.
    There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
    A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
    Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.
    Example :
    Input: nums = [2,10,7,5,4,1,8,6]
    Output: 5
    Explanation: 
    The minimum element in the array is nums[5], which is 1.
    The maximum element in the array is nums[1], which is 10.
    We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
    This results in 2 + 3 = 5 deletions, which is the minimum number possible.
"""


from typing import List
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        minIndex = nums.index(min(nums))
        maxIndex = nums.index(max(nums))

        left = min(minIndex, maxIndex)
        right = max(minIndex, maxIndex)

        return min(
            right + 1,
            n - left,
            left + 1 + n - right
        )