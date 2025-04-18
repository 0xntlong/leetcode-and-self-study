"""
1718. Construct the Lexicographically Largest Valid Sequence
    Given an integer n, find a sequence that satisfies all of the following:
    The integer 1 occurs once in the sequence.
    Each integer between 2 and n occurs twice in the sequence.
    For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
    The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
    Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
    A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

    Example :
    Input: n = 3
    Output: [3,1,2,3,2]
    Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
"""

from typing import List
class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        sequence = [0] * (2 * n - 1)
        seen = set()
        def dfs(i):
            if i == len(sequence):
                return True
            if sequence[i]:
                return dfs(i + 1)
            for j in range(n, 0, - 1):
                if j in seen:
                    continue
                seen.add(j)
                sequence[i] = j
                if j == 1:
                    if dfs(i + 1):
                        return True
                elif i + j < len(sequence) and sequence[i + j] == 0:
                    sequence[i + j] = j
                    if dfs(i + 1):
                        return True
                    sequence[i + j] = 0
                sequence[i] = 0
                seen.remove(j)
            return False
        dfs(0)
        return sequence