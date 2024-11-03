"""
1539. Kth Missing Positive Number
    Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
    Return the kth positive integer that is missing from this array.

    Example :
    Input: arr = [2,3,4,7,11], k = 5
    Output: 9
    Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
"""


from typing import List
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        i = 0
        n = len(arr)
        while i < n:
            mid = i + (n - i) // 2
            if arr[mid] - mid > k:
                n = mid
            else:
                i = mid + 1
        return i + k