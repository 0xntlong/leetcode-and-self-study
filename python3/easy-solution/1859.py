"""
1859. Sorting the Sentence
    A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
    A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
    For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
    Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

    Example :
    Input: s = "is2 sentence4 This1 a3"
    Output: "This is a sentence"
    Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.
"""


class Solution:
    def sortSentence(self, s: str) -> str:
        ans = ""
        words = s.split()
        for i in range(0, len(words)):
            for j in range(i, len(words)):
                if int(words[i][-1]) > int(words[j][-1]):
                    count = words[j]
                    words[j] = words[i]
                    words[i] = count
        for i, word in enumerate(words):
            if i == 0:
                ans += word[:- 1]
            else:
                ans += " " + word[:-1]
        return ans
        