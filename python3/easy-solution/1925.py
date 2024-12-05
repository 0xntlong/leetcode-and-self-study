"""
1925. Count Square Sum Triples
    A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
    Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

    Example :
    Input: n = 5
    Output: 2
    Explanation: The square triples are (3,4,5) and (4,3,5).
"""

import math
class Solution:
    def countTriples(self, n: int) -> int:
        count = 0
        for i in range(3, n):
            sq_i = i * i
            for j in range(3, n):
                sq_j = sq_i + j * j
                c = int(math.sqrt(sq_j))
                if c > n:
                    break
                if c * c == sq_j:
                    count += 1
        return count