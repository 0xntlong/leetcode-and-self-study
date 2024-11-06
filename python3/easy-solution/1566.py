"""
1566. Detect Pattern of Length M Repeated K or More Times
    Given an array of positive integers arr, find a pattern of length m that is repeated k or more times.
    A pattern is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times consecutively without overlapping. A pattern is defined by its length and the number of repetitions.
    Return true if there exists a pattern of length m that is repeated k or more times, otherwise return false.

    Example :
    Input: arr = [1,2,4,4,4,4], m = 1, k = 3
    Output: true
    Explanation: The pattern (4) of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
"""

from typing import List
class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        count = 0
        for i in range(len(arr) - m):
            if arr[i] == arr[i + m]:
                count += 1
            else :
                count = 0
            if count == ( k - 1) * m:
                return True 
        return False