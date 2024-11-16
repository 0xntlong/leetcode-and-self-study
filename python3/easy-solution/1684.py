"""
1684. Count the Number of Consistent Strings
    You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
    Return the number of consistent strings in the array words.

    Example:
    Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
    Output: 2
    Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
"""


from typing import List 
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        result = 0
        hashset = set(allowed)
        for word in words:
            if all(x in hashset for x in word):
                result += 1
        return result