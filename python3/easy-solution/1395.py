"""
1935. Maximum Number of Words You Can Type
    There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
    Example :
    Input: text = "hello world", brokenLetters = "ad"
    Output: 1
    Explanation: We cannot type "world" because the 'd' key is broken.
"""



class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)
        count = 0
        for w in text.split():
            if all(c not in broken for c in w):
                count += 1
        return count