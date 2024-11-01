"""
1502. Can Make Arithmetic Progression From Sequence
    A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
    Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

    Example :
    Input: arr = [3,5,1]
    Output: true
    Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
"""

from typing import List
class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        r = arr[1] - arr[0]
        for i in range(len(arr) - 1):
            if (arr[i + 1] - arr[i]) != r:
                return False
        return True