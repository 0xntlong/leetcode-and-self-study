"""
1408. String Matching in an Array
    Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
    A substring is a contiguous sequence of characters within a string

    Example :
    Input: words = ["mass","as","hero","superhero"]
    Output: ["as","hero"]
    Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
    ["hero","as"] is also a valid answer.
"""

from typing import List
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        result = []
        for i in range(len(words)):
            for j in range(len(words)):
                if i != j:
                    if words[i] in words[j]:
                        result.append(words[i])
                        break
        return result