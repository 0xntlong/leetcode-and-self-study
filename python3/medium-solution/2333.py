"""
2333. Minimum Sum of Squared Difference
    You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.
    The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.
    You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.
    Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
    Note: You are allowed to modify the array elements to become negative integers.

    Example :
    Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
    Output: 579
    Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
    The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
"""


class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        d = [abs(a - b) for a, b in zip(nums1, nums2)]

        if sum(d) <= k:
            return 0

        d.sort(reverse = True)
        d.append(0)
        n = len(nums1)

        for i in range(1, n + 1):
            cost = (d[i - 1] - d[i]) * i

            if cost > k:
                q, r = divmod(k, i)
                hi = d[i - 1] - q

                return (
                    hi * hi * (i - r)
                    + (hi - 1) * (hi - 1) * r
                    + sum(x * x for x in d[i:n])
                )

            k -= cost

        return 0