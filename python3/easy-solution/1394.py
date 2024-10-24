"""
1394. Find Lucky Integer in an Array
    Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
    Return the largest lucky integer in the array. If there is no lucky integer return -1.
    
    Example :
    Input: arr = [2,2,3,4]
    Output: 2
    Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
"""
from typing import List
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        hash_map = [0] * 501
        n = len(arr)
        lucky = -1
        for i in range(n):
            hash_map[arr[i]] += 1
        for i in range(1, 501):
            if hash_map[i] == i:
                lucky = max(lucky, i)
        return lucky
