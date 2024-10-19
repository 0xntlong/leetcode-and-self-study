"""
1346. Check If N and Its Double Exist
    Given an array arr of integers, check if there exist two indices i and j such that :
    i != j
    0 <= i, j < arr.length
    arr[i] == 2 * arr[j]
    Example:

    Input: arr = [10,2,5,3]
    Output: true
    Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
""" 
from typing import List
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        N = len(arr)
        for i in range(N):
            for j in range(N):
                if i != j and arr[i] == 2 * arr[j]:
                    return True
        return False
            