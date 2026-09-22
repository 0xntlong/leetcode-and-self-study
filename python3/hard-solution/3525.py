"""
3525. Find X Value of Array II
    You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].
    You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.
    The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.
    For each query in queries you need to determine the x-value of nums for xi after performing the following actions:
    Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
    Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
    Return an array result of size queries.length where result[i] is the answer for the ith query.
    A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
    A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
    Note that the prefix and suffix to be chosen for the operation can be empty.
    Note that x-value has a different definition in this version.

    Example :

    Input: nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
    Output: [2,2,2]
    Explanation:
    For query 0, nums becomes [1, 2, 2, 4, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 4, 5]. nums becomes [1, 2].
    Remove the empty suffix. nums becomes [1, 2, 2, 4, 5] with a product 80, which gives remainder 2 when divided by 3.
    For query 1, nums becomes [1, 2, 2, 3, 5], and the prefix [1, 2, 2] must be removed. The possible operations are:
    Remove the empty suffix. nums becomes [3, 5].
    Remove the suffix [5]. nums becomes [3].
    For query 2, nums becomes [1, 2, 2, 3, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 2, 3, 5]. nums becomes [1].
    Remove the suffix [3, 5]. nums becomes [1, 2, 2].
"""

from typing import List


class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)
        size = 1
        while size < n:
            size <<= 1
        H = [0] * (2 * size * k)
        prod = [1 % k] * (2 * size)

        for i in range(n):
            v = nums[i] % k
            nd = size + i
            H[nd * k + v] = 1
            prod[nd] = v

        for i in range(size - 1, 0, -1):
            lc = 2 * i
            rc = lc + 1
            lp = prod[lc]

            bi = i * k
            bl = lc * k
            br = rc * k

            for q in range(k):
                H[bi + q] = H[bl + q]
            for q in range(k):
                c = H[br + q]
                if c:
                    H[bi + (lp * q) % k] += c
            prod[i] = lp * prod[rc] % k

        def update(idx: int, val: int) -> None:
            nd = size + idx
            base = nd * k
            for q in range(k):
                H[base + q] = 0
            v = val % k
            H[base + v] = 1
            prod[nd] = v
            i = nd >> 1

            while i:
                lc = 2 * i
                rc = lc + 1
                lp = prod[lc]
                bi = i * k
                bl = lc * k
                br = rc * k
                for q in range(k):
                    H[bi + q] = H[bl + q]
                for q in range(k):
                    c = H[br + q]
                    if c:
                        H[bi + (lp * q) % k] += c
                prod[i] = lp * prod[rc] % k
                i >>= 1

        ans = []

        for idx, val, start, x in queries:
            update(idx, val)
            l = start + size
            r = n + size
            ln = []
            rn = []
            while l < r:
                if l & 1:
                    ln.append(l)
                    l += 1
                if r & 1:
                    r -= 1
                    rn.append(r)
                l >>= 1
                r >>= 1

            rn.reverse()
            res = [0] * k
            p = 1 % k

            for nd in ln:
                base = nd * k
                for q in range(k):
                    c = H[base + q]
                    if c:
                        res[(p * q) % k] += c
                p = p * prod[nd] % k

            for nd in rn:
                base = nd * k
                for q in range(k):
                    c = H[base + q]
                    if c:
                        res[(p * q) % k] += c
                p = p * prod[nd] % k
            ans.append(res[x])

        return ans