"""
2180. Count Interger With Even Digit Sum
    Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.
    The digit sum of a positive integer is the sum of all its digits.
    
    Example :
    Input: num = 4
    Output: 2
    Explanation:
    The only integers less than or equal to 4 whose digit sums are even are 2 and 4.  
"""

class Solution:
    def countEven(self, num: int) -> int:
        # res = 0
        # for i in range(1,num + 1):
        #     digit_sum = sum(int(d) for d in str(i))
        #     if digit_sum % 2 == 0:
        #         res += 1
        # return res

        return num // 2 if sum([int(k) for k in str(num)]) % 2 == 0 else (num - 1) // 2