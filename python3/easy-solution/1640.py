"""
1640. Check Array Formation Through Concatenation
    You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
    Return true if it is possible to form the array arr from pieces. Otherwise, return false.

    Example :
    Input: arr = [15,88], pieces = [[88],[15]]
    Output: true
    Explanation: Concatenate [15] then [88]
"""

from typing import List
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        hashmap = {num : i for i, num in enumerate(arr)}
        for p in pieces:
            if len(p) == 1:
                if p[0] not in hashmap:
                    return False
            else :
                if p[0] not in hashmap:
                    return False
                arr_iter = hashmap[p[0]]
                for num in p:
                    if num not in hashmap:
                        return False
                    if hashmap[num] != arr_iter:
                        return False
                    arr_iter += 1
        return True
