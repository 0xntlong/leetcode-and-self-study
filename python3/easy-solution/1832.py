"""
1832. Check if the Sentence Is Pangram
    A pangram is a sentence where every letter of the English alphabet appears at least once.
    Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

    Example :
    Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
    Output: true
    Explanation: sentence contains at least one of every letter of the English alphabet.
"""

class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        arr = [0] * 26
        count = 0
        for c in sentence:
            idx = ord(c) - ord('a')
            if arr[idx] == 0:
                arr[idx] += 1
                count += 1
        return count == 26