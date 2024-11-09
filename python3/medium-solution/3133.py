"""
3133. Minimum Array End
    You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
    Return the minimum possible value of nums[n - 1].
    
    Example :
    Input: n = 3, x = 4
    Output: 6
    Explanation:
    nums can be [4,5,6] and its last element is 6.
"""

class Solution:
    def minEnd(self, n: int, x: int) -> int:
        result = x
        remain = n - 1
        position = 1
        while remain:
            if not ( x & position):
                result |= (remain & 1) * position
                remain >>= 1
            position <<= 1
        return result