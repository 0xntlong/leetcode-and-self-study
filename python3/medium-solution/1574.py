"""
1574. Shortest Subarray to be Removed to Make Array Sorted
    Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
    Return the length of the shortest subarray to remove.
    A subarray is a contiguous subsequence of the array.

    Example :
    Input: arr = [1,2,3,10,4,2,3,5]
    Output: 3
    Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
    Another correct solution is to remove the subarray [3,10,4].
"""

from typing import List
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n , left = len(arr), 0
        while left + 1 < n and arr[left] <= arr[left + 1]:
            left += 1
        if left == n - 1:
            return 0
        stack = [n - 1]
        for right in range(n - 2, left, -1):
            if arr[right] <= arr[right + 1]:
                stack.append(right)
            else:
                break
        remove = min(n - left - 1, stack[-1])
        for i in range(0, left + 1):
            while stack and arr[i] > arr[stack[-1]]:
                stack.pop()
            if stack:
                remove = min(remove, stack[-1] - i - 1)
        return remove
                