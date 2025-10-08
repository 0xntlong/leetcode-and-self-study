"""
2300. Successful Pairs of Spells and Potions
    You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
    You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
    Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

    Example :

    Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    Output: [4,0,3]
    Explanation:
    - 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
    - 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
    - 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
    Thus, [4,0,3] is returned.
"""

from typing import List
from collections import Counter
from itertools import accumulate
from bisect import bisect_left

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        """
        potions.sort()
        pairs = []
        for i in range(len(spells)):
            l = 0
            r = len(potions) - 1
            idx = len(potions)
            while l <= r:
                mid = l + (r - l) // 2
                if spells[i] * potions[mid] >= success:
                    idx = mid
                    r = mid - 1
                elif spells[i] * potions[mid] < success:
                    l = mid + 1
            pairs.append(len(potions) - idx)
        return pairs
        """
        freq = Counter(potions)
        maxFreq = max(freq)
        prefix = [0] * (1 + maxFreq)
        for p, f in freq.items():
            prefix[p] = f
        freq = list(accumulate(prefix))
        n, m = len(spells), len(potions)
        res = [0] * n
        for i, x in enumerate(spells):
            k = (success + x - 1) // x
            if k <= maxFreq:
                res[i] = m - freq[k - 1]
        return res

        """
        potions.sort()
        pairs = []
        for s in spells:
            n = (success + s - 1) // s
            idx = bisect_left(potions, n)
            pairs.append(len(potions) - idx)
        return pairs
        """