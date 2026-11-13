"""
3420. Count Non-Decreasing Subarrays After K Operations
    You are given an array nums of n integers and an integer k.
    For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.
    Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.
    Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.

    Example :
    Input: nums = [6,3,1,2,4,4], k = 7
    Output: 17
    Explanation:
    Out of all 21 possible subarrays of nums, only the subarrays [6, 3, 1], [6, 3, 1, 2], [6, 3, 1, 2, 4] and [6, 3, 1, 2, 4, 4] cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is 21 - 4 = 17.
"""


from ast import List

from collections import deque
class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        right = len(nums) - 1
        total_cost = 0
        q = deque() 
        res = 0

        for left in range(len(nums)-1, -1, -1):
            x = nums[left]
            c = 1

            while q and q[0][0] < x:
                value, count = q.popleft()    
                total_cost += (x - value) * count
                c += count
            
            q.appendleft((x,c))
                
            while k < total_cost:
                value, c = q.pop()

                total_cost -= value - nums[right]
                right -= 1

                if c > 1:
                    q.append((value, c - 1))

            res += right - left + 1
        
        return res