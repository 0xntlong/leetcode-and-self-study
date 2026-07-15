"""
3658. GCD of Odd and Even Sums
    You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
    sumOdd: the sum of the smallest n positive odd numbers.
    sumEven: the sum of the smallest n positive even numbers.
    Return the GCD of sumOdd and sumEven.

    Example :
    Input: n = 4
    Output: 4
    Explanation:
    Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
    Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
    Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.
"""



class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        if n == 1:
            return 1

        sum_even = 0
        sum_odd = 0

        for i in range(1, n * 2):
            if i % 2 == 0:
                sum_even += i

            else:
                sum_odd += i

        num = min(sum_even, sum_odd)
        num2 = max(sum_even, sum_odd)

        while num > 0:
            x = num
            if num2 % num == 0:
                return num

            num = num2 % num
            num2 = x

        return num
        