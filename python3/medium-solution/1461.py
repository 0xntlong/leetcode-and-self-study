"""
1461. Check If a String Contains All Binary Codes of Size K
    Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
    Example :
    Input: s = "00110110", k = 2
    Output: true
    Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
"""


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        req = 1 << k
        n = len(s)
        if req > n - k + 1:
            return False
        seen = [False] * req
        mask = req - 1 
        code = 0
        found = 0
        for i, ch in enumerate(s):
            code = ((code << 1) & mask) | (ch == '1')
            if i >= k - 1:
                if not seen[code]:
                    seen[code] = True
                    found += 1
                    if found == req:
                        return True

        return False