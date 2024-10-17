"""
670. Maximum Swap
    You are given an integer num. You can swap two digits at most once to get the maximum valued number.
    Return the maximum valued number you can get.
    Example :
    Input: num = 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.
"""

# FRIST APPROACH
class Solution:
    def maximumSwap(self, num: int) -> int:
        digit = []
        current = num
        while current > 0:
            digit.append(current % 10)
            current //= 10
        digit.reverse()
        max_digit = num
        N = len(digit)
        for i in range(N):
            for j in range(i + 1, N):
                digit[i], digit[j] = digit[j], digit[i]
                score = 0
                for k in range(N):
                    score *= 10
                    score += digit[k]
                max_digit = max(max_digit, score)
                digit[i], digit[j] = digit[j], digit[i]
        return max_digit
    

# SECOND APPROACH
class Solution:
    def maximumSwap(self, num: int) -> int:
        digit = list(str(num))
        max_digit = "0"
        max_index = -1
        x = y = -1
        for i in reversed(range(len(digit))):
            if digit[i] > max_digit:
                max_digit = digit[i]
                max_index = i
            if digit[i] < max_digit:
                x, y = i, max_index
        if x != -1:
            digit[x], digit[y] = digit[y], digit[x]

        return int("".join(digit))