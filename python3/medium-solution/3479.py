"""
3479. Fruits Into Baskets III
    You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
    From left to right, place the fruits according to these rules:
    Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
    Each basket can hold only one type of fruit.
    If a fruit type cannot be placed in any basket, it remains unplaced.
    Return the number of fruit types that remain unplaced after all possible allocations are made.

    Example :
    Input: fruits = [4,2,5], baskets = [3,5,4]
    Output: 1
    Explanation:
    fruits[0] = 4 is placed in baskets[1] = 5.
    fruits[1] = 2 is placed in baskets[0] = 3.
    fruits[2] = 5 cannot be placed in baskets[2] = 4.
    Since one fruit type remains unplaced, we return 1.
"""


from typing import List

class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size *= 2
        self.seg = [-1] * (2 * self.size)
        self.build(data, 1, 0, self.n - 1)

    def build(self, data, idx, l, r):
        if l == r:
            self.seg[idx] = data[l]
        else:
            m = (l + r) // 2
            self.build(data, 2 * idx, l, m)
            self.build(data, 2 * idx + 1, m + 1, r)
            self.seg[idx] = max(self.seg[2 * idx], self.seg[2 * idx + 1])

    def search(self, idx, l, r, k):
        if self.seg[idx] < k:
            return -1
        if l == r:
            self.seg[idx] = -1
            return l
        m = (l + r) // 2
        if self.seg[2 * idx] >= k:
            pos = self.search(2 * idx, l, m, k)
        else:
            pos = self.search(2 * idx + 1, m + 1, r, k)
        self.seg[idx] = max(self.seg[2 * idx], self.seg[2 * idx + 1])
        return pos


class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        seg = SegmentTree(baskets)
        unplaced = 0
        for fruit in fruits:
            if seg.search(1, 0, n - 1, fruit) == -1:
                unplaced += 1
        return unplaced