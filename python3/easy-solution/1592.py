"""
1592. Rearrange Spaces Between Words
    You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
    Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
    Return the string after rearranging the spaces.
    Example :

    Input: text = "  this   is  a sentence "
    Output: "this   is   a   sentence"
    Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
"""

class Solution:
    def reorderSpaces(self, text: str) -> str:
        space = text.count(' ')
        words = [word for word in text.split() if word]
        if len(words) == 1:
            return words[0] + ' ' * space
        k = space // (len(words) - 1)
        remain = space % (len(words) - 1)
        ans = (' ' * k).join(words)
        ans += ' ' * remain
        return ans