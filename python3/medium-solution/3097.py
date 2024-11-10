"""
3097. Shortest Path in a Hidden Grid
You are given an array nums of non-negative integers and an integer k.
An array is called special if the bitwise OR of all of its elements is at least k.
Return the length of the shortest special non-empty 
subarray of nums, or return -1 if no special subarray exists.

Example :
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.
"""


class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        BitCount = [0] * 32
        XOR = 0
        left = 0
        Min = float('inf')
        for right in range(n):
            XOR |= nums[right]
            for bit in range(32):
                if nums[right] & (1 << bit):
                    BitCount[bit] += 1
            while left <= right and XOR >= k:
                Min = min(Min, right - left + 1)
                updateXOR = 0
                for bit in range(32):
                    if nums[left] & (1 << bit):
                        BitCount[bit] -= 1
                    if BitCount[bit] > 0:
                        updateXOR |= (1 << bit)
                XOR = updateXOR
                left += 1
        return -1 if Min == float('inf') else Min