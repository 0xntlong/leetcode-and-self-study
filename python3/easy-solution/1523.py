"""
1523. Count Odd Numbers in an Interval Range
    Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
    
    Example :
    Input: low = 3, high = 7
    Output: 3
    Explanation: The odd numbers between 3 and 7 are [3,5,7].
"""


class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low) // 2 + 1 if low % 2 != 0 or high % 2 != 0 else (high - low) // 2