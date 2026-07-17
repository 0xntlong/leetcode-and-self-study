"""
3312. Sorted GCD Pair Queries
    You are given an integer array nums of length n and an integer array queries.

    Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.

    For each query queries[i], you need to find the element at index queries[i] in gcdPairs.

    Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.

    The term gcd(a, b) denotes the greatest common divisor of a and b.

    Example 1:

    Input: nums = [2,3,4], queries = [0,2,2]

    Output: [1,2,2]

    Explanation:

    gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1].

    After sorting in ascending order, gcdPairs = [1, 1, 2].

    So, the answer is [gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2].
"""



class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        max_value = max(nums)
        freq = [0] * (max_value + 1)
        for i in nums:
            freq[i] += 1
        cnt = [0] * (max_value + 1)
        for j in range(max_value, 0, -1):
            total = 0
            for x in range(j, max_value + 1, j):
                total += freq[x]
            pairs = total * (total - 1) // 2
            
            for x in range(2 * j, max_value + 1, j):
                pairs -= cnt[x]
            cnt[j] = pairs
        pref = []
        vals = []
        s = 0
        for j in range(1, max_value + 1):
            if cnt[j]:
                s += cnt[j]
                pref.append(s)
                vals.append(j)
        res = []
        for q in queries:
            res.append(vals[bisect_left(pref, q + 1)])
        return res