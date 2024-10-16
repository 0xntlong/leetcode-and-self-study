"""
1405. Longest Happy String
    A string s is called happy if it satisfies the following conditions:
    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.
    Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
    A substring is a contiguous sequence of characters within a string.
    
    Example :
    Input: a = 1, b = 1, c = 7
    Output: "ccaccbcc"
    Explanation: "ccbccacc" would also be a correct answer.
"""

import heapq
class Solution:
    def longestDecomposition(self, a: int, b: int, c: int) -> str:
        res, pq = "", []
        for count, char in [(a, 'a'), (b, 'b'), (c, 'c')]:
            if count != 0:
                heapq.heappush(pq, (count, char))
        while pq:
            count, char = heapq.heappop(pq)
            if len(res) > 1 and res[-1] == res[-2] == char:
                if not pq:
                    break
                count2, char2 = heapq.heappop(pq)
                res += char2 
                count2 += 1
                if count2:
                    heapq.heappush(pq, (count2, char2))
            else:
                res += char
                count -= 1
                if count:
                    heapq.heappush(pq, (count, char))
        return res