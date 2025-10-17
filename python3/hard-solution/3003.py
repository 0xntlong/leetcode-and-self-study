"""
3003. Maximize the Number of Partitions After Operations
    You are given a string s and an integer k.
    First, you are allowed to change at most one index in s to another lowercase English letter.
    After that, do the following partitioning operation until s is empty:
    Choose the longest prefix of s containing at most k distinct characters.
    Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
    Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

    Example :
    Input: s = "accca", k = 2
    Output: 3
    Explanation:
    The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".
    Then we perform the operations:
    The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
    Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
    Finally, we remove "a" and s becomes empty, so the procedure ends.
    Doing the operations, the string is divided into 3 partitions, so the answer is 3.
"""

class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        L = [[0] * 3 for _ in range(n)]
        R = [[0] * 3 for _ in range(n)]

        num, mask, cnt = 0, 0, 0
        for i in range(n - 1):
            bit_mask = 1 << (ord(s[i]) - ord('a'))
            if not (mask & bit_mask):
                cnt += 1
                if cnt <= k:
                    mask |= bit_mask
                else:
                    num += 1
                    mask = bit_mask
                    cnt = 1
            L[i+1][0] = num
            L[i+1][1] = mask
            L[i+1][2] = cnt
        num, mask, cnt = 0, 0, 0
        for i in range(n - 1, 0, -1):
            bit_mask = 1 << (ord(s[i]) - ord('a'))
            if not (mask & bit_mask):
                cnt += 1
                if cnt <= k:
                    mask |= bit_mask
                else:
                    num += 1
                    mask = bit_mask
                    cnt = 1
            R[i-1][0] = num
            R[i-1][1] = mask
            R[i-1][2] = cnt
        max_val = 0
        for i in range(n):
            seg = L[i][0] + R[i][0] + 2
            split = L[i][1] | R[i][1]
            count = bin(split).count('1')
            if L[i][2] == k and R[i][2] == k and count < 26:
                seg += 1
            elif min(count + 1, 26) <= k:
                seg -= 1
            max_val = max(max_val, seg)
        return max_val