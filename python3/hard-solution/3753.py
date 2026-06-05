"""
3753. Total Waviness of Numbers in Range II
    You are given two integers num1 and num2 representing an inclusive range [num1, num2].
    The waviness of a number is defined as the total count of its peaks and valleys:
    A digit is a peak if it is strictly greater than both of its immediate neighbors.
    A digit is a valley if it is strictly less than both of its immediate neighbors.
    The first and last digits of a number cannot be peaks or valleys.
    Any number with fewer than 3 digits has a waviness of 0.
    Return the total sum of waviness for all numbers in the range [num1, num2].

    Example :
    Input: num1 = 120, num2 = 130
    Output: 3
    Explanation:
    In the range [120, 130]:

    120: middle digit 2 is a peak, waviness = 1.
    121: middle digit 2 is a peak, waviness = 1.
    130: middle digit 3 is a peak, waviness = 1.
    All other numbers in the range have a waviness of 0.
    Thus, total waviness is 1 + 1 + 1 = 3.
"""



class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def helper(num: int) -> int:
            if num <= 0:
                return 0
            digits = list(map(int, str(num)))
            m = len(digits)
            dp = {}

            def get_dir(a: int, b: int) -> int:
                if a < b:
                    return 0
                if a == b:
                    return 1
                return 2

            def match_dir(dir1: int, dir2: int) -> bool:
                return (dir1 == 0 and dir2 == 2) or (dir1 == 2 and dir2 == 0)

            for first_pos in range(m):
                max_first_digit = digits[0] if first_pos == 0 else 9
                for first_digit in range(1, max_first_digit + 1):
                    tie = first_digit < digits[0] if first_pos == 0 else True
                    last_dir = 1
                    key = (first_pos, tie, last_dir, first_digit)
                    if key not in dp:
                        dp[key] = [0, 0]
                    dp[key][1] += 1

            for pos in range(m - 1):
                for tie in [False, True]:
                    for last_dir in range(3):
                        for last_digit in range(10):
                            key = (pos, tie, last_dir, last_digit)
                            if key not in dp:
                                continue
                            total_waviness, total_ways = dp[key]
                            if total_ways == 0:
                                continue
                            max_next_digit = 9 if tie else digits[pos + 1]
                            for next_digit in range(max_next_digit + 1):
                                new_tie = tie or (next_digit < digits[pos + 1])
                                new_dir = get_dir(last_digit, next_digit)
                                new_key = (pos + 1, new_tie, new_dir, next_digit)
                                if new_key not in dp:
                                    dp[new_key] = [0, 0]
                                dp[new_key][0] += total_waviness + total_ways * int(match_dir(last_dir, new_dir))
                                dp[new_key][1] += total_ways

            ans = 0
            for tie in [False, True]:
                for last_dir in range(3):
                    for last_digit in range(10):
                        key = (m - 1, tie, last_dir, last_digit)
                        if key in dp:
                            ans += dp[key][0]
            return ans
        return helper(num2) - helper(num1 - 1)