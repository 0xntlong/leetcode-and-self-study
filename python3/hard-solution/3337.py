"""
3337. Total Characters in String After Transformations II
    You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:
    Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
    The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
    Return the length of the resulting string after exactly t transformations.
    Since the answer may be very large, return it modulo 109 + 7.
    Example :
    Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]
    Output: 7
    Explanation:
    First Transformation (t = 1):

    'a' becomes 'b' as nums[0] == 1
    'b' becomes 'c' as nums[1] == 1
    'c' becomes 'd' as nums[2] == 1
    'y' becomes 'z' as nums[24] == 1
    'y' becomes 'z' as nums[24] == 1
    String after the first transformation: "bcdzz"
    Second Transformation (t = 2):
    'b' becomes 'c' as nums[1] == 1
    'c' becomes 'd' as nums[2] == 1
    'd' becomes 'e' as nums[3] == 1
    'z' becomes 'ab' as nums[25] == 2
    'z' becomes 'ab' as nums[25] == 2
    String after the second transformation: "cdeabab"
    Final Length of the string: The string is "cdeabab", which has 7 characters.
"""


from typing import List

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        mod = 10**9 + 7
        vector = [[0] * 26 for _ in range(26)]
        for c in range(26):
            num = nums[c]
            for j in range(1, num + 1):
                next_c = (c + j) % 26
                vector[c][next_c] += 1
        def matrix_multi(x, y):
            res = [[0] * 26 for _ in range(26)]
            for i in range(26):
                for j in range(26):
                    if x[i][j] == 0:
                        continue
                    for l in range(26):
                        res[i][l] = (res[i][l] + x[i][j] * y[j][l]) % mod
            return res
        def matrix_pol(m, n):
            total = [[1 if i == j else 0 for j in range(26)] for i in range(26)]
            while n > 0:
                if n % 2 == 1:
                    total = matrix_multi(total, m)
                m = matrix_multi(m, m)
                n //= 2
            return total
        compute = matrix_pol(vector, t)
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        new_cnt =[0] * 26
        for i in range(26):
            for j in range(26):
                new_cnt[j] = (new_cnt[j] + cnt[i] * compute[i][j]) % mod                  
        result = 0
        for x in new_cnt:
            result = (result + x) % mod
        return result