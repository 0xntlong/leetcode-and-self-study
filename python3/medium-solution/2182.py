"""
2182. Construct String With Repeat Limit
    You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
    Return the lexicographically largest repeatLimitedString possible.
    A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

    Example :
    Input: s = "cczazcc", repeatLimit = 3
    Output: "zzcccac"
    Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
    The letter 'a' appears at most 1 time in a row.
    The letter 'c' appears at most 3 times in a row.
    The letter 'z' appears at most 2 times in a row.
    Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
    The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
    Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
"""

from collections import Counter
import heapq
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = Counter(s)
        max_heap = []
        for char, count in freq.items():
            heapq.heappush(max_heap, (-ord(char), count))
        result = []
        while max_heap:
            val, count = heapq.heappop(max_heap)
            char = chr(-val)
            use_count = min(count, repeatLimit)
            result.append(char * use_count)
            count -= use_count
            if count > 0:
                if not max_heap:
                    break
                next_val, next_count = heapq.heappop(max_heap)
                next_char = chr(-next_val)
                result.append(next_char)
                next_count -= 1
                if next_count > 0:
                    heapq.heappush(max_heap, (next_val, next_count))
                heapq.heappush(max_heap, (val, count))
        return ''.join(result)

