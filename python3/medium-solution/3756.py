"""
3756. Concatenate Non-Zero Digits and Multiply by Sum II
    You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
    For each queries[i], extract the substring s[li..ri]. Then, perform the following:
    Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x. The answer is x * sum.
    Return an array of integers answer where answer[i] is the answer to the ith query.
    Since the answers may be very large, return them modulo 109 + 7.

    Example :
    Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
    Output: [12340, 4, 9]
    Explanation:
    s[0..7] = "10203004"
    x = 1234
    sum = 1 + 2 + 3 + 4 = 10
    Therefore, answer is 1234 * 10 = 12340.
    s[1..3] = "020"
    x = 2
    sum = 2
    Therefore, the answer is 2 * 2 = 4.
    s[4..6] = "300"
    x = 3
    sum = 3
    Therefore, the answer is 3 * 3 = 9.
"""



from typing import List


class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        idx = [0] * (n + 1)
        val = [0] * (n + 1)
        total = [0] * (n + 1)
        pow10 = [1] * (n + 1)

        for i in range(1, n + 1):
            pow10[i] = pow10[i - 1] * 10 % MOD

        count = 0

        for i, ch in enumerate(s):
            digit = int(ch)

            if digit != 0:
                count += 1
                val[count] = (val[count - 1] * 10 + digit) % MOD
                total[count] = total[count - 1] + digit

            idx[i + 1] = count

        ans = []

        for left, right in queries:
            a = idx[left]
            b = idx[right + 1]

            if a == b:
                ans.append(0)
                continue

            length = b - a

            num = (val[b] - val[a] * pow10[length]) % MOD
            digit_sum = total[b] - total[a]

            ans.append(num * digit_sum % MOD)

        return ans