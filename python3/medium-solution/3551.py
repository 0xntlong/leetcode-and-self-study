"""
3551. Minimum Swaps to Sort by Digit Sum
    You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have the same digit sum, the smaller number appears first in the sorted order.
    Return the minimum number of swaps required to rearrange nums into this sorted order.
    A swap is defined as exchanging the values at two distinct positions in the array.
    Example :
    Input: nums = [37,100]
    Output: 1
    Explanation:
    Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]
    Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the sorted order.
    Thus, the minimum number of swaps required to rearrange nums is 1.
"""


from typing import List
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            curr = num
            digit_sum = 0
            while curr:
                digit_sum += curr % 10
                curr //= 10
            nums[i] = (digit_sum, num, i)
        nums.sort()
        nums = [num[2] for num in nums]
        n = len(nums)
        visited = [False] * n
        cycle = 0

        for i, num in enumerate(nums):
            if visited[i]:
                continue
            
            cycle += 1
            j = i
            while not visited[j]:
                visited[j] = True
                j = nums[j]
        print(n, cycle)
            
        return n - cycle