"""
1805. Number of Different Integers in a String
    You are given a string word that consists of digits and lowercase English letters.
    You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".
    Return the number of different integers after performing the replacement operations on word.
    Two integers are considered different if their decimal representations without any leading zeros are different.

    Example :
    Input: word = "a123bc34d8ef34"
    Output: 3
    Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
"""

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        for char in word:
            if not char.isdigit():
                word = word.replace(char, " ")
        nums = set(num.lstrip("0") for num in word.split() if num)
        return len(nums)