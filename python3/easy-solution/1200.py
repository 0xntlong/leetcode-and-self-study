"""
1200. Minimum Absolute Difference
    Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
    Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
    a, b are from arr
    a < b
    b - a equals to the minimum absolute difference of any two elements in arr
    Example :
    Input: arr = [4,2,1,3]
    Output: [[1,2],[2,3],[3,4]]
    Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
"""


from typing import List


class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        min_diff = float('inf')
        for i in range(n - 1):
            curr = arr[i + 1] - arr[i]
            if curr < min_diff:
                min_diff = curr
        res = []
        for i in range(n - 1):
            if (abs(arr[i] - arr[i + 1])) <= min_diff:
                res.append([arr[i], arr[i + 1]])
        return res