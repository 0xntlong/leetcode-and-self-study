"""
1619. Mean of Array After Removing Some Elements
    Given an integer array arr, return the mean of the remaining integers after removing the smallest 5% and the largest 5% of the elements.
    Answers within 10-5 of the actual answer will be considered accepted.

    Example :
    Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
    Output: 2.00000
    Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
"""

from typing import List
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        percent_5 = (len(arr)*5)//100
        total, count = 0, 0
        for i in range(percent_5, len(arr) - percent_5):
            total += arr[i]
            count += 1
        return total / count if count > 0 else 0