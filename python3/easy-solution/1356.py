"""
1356. Sort Integers by The Number of 1 Bits
    You are given an integer array arr. 
    Sort the integers in the array in ascending order by the number of 1's in their binary representation 
    and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
    Return the array after sorting it.
    
    Example :
    Input: arr = [0,1,2,3,4,5,6,7,8]
    Output: [0,1,2,4,8,3,5,6,7]
    Explantion: [0] is the only integer with 0 bits.
    [1,2,4,8] all have 1 bit.
    [3,5,6] have 2 bits.
    [7] has 3 bits.
    The sorted array by bits is [0,1,2,4,8,3,5,6,7]
"""
from typing import List
import heapq
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        def count_one(num):
            count = 0
            while num:
                num &= (num - 1)
                count += 1
            return count 
        stack = []
        for i in arr:
            ones = count_one(i)
            stack.append((ones, i))
        heapq.heapify(stack)
        res = []
        while stack:
            res.append(heapq.heappop(stack)[1])
        return res