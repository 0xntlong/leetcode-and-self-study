"""
744. Find Smallest Letter Greater Than Target
    You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
    Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

    Example :
    Input: letters = ["c","f","j"], target = "a"
    Output: "c"
    Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
"""



class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        low = 0
        high = n - 1
        min_letter = 'z'
        count = 0
        while low <= high:
            mid = (low + high) // 2
            if letters[mid] > target:
                min_letter = min(letters[mid], min_letter)
                high = mid - 1
                count = 1
            else:
                low = mid + 1
        if count == 0:
            return letters[0]
        return min_letter