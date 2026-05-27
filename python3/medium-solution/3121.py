"""
3121. Count the Number of Special Characters II
    You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
    Return the number of special letters in word.
    
    Example:
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:

    The special characters are 'a', 'b', and 'c'.
"""



class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count = 0
        for w in set(word.lower()):
            if w.upper() in word and w in word:
                if word.rfind(w) < word.find(w.upper()):
                    count += 1
        return count