"""
2081. Sum of k-Mirror Numbers
    A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
    For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
    On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
    Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

    Example :
    Input: k = 2, n = 5
    Output: 25
    Explanation:
    The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
    base-10    base-2
        1          1
        3          11
        5          101
        7          111
        9          1001
    Their sum = 1 + 3 + 5 + 7 + 9 = 25.
"""



class Solution:
    digit = [0] * 64
    def palindrome(self, x: int , k : int) -> bool:
        digit = []
        while x > 0:
            digit.append(x % k)
            x //= k
        return digit == digit[::-1]

    def isPalindrome(self, mid: int, odd: bool) -> int:
        if odd:
            return mid * (10 ** (len(str(mid)) - 1)) + self.reverse(mid // 10)
        else:
            return mid * (10 ** len(str(mid))) + self.reverse(mid)

    def reverse(self, x: int) -> int:
        res = 0
        while x > 0:
            res = res * 10 + x % 10
            x //= 10
        return res

    def kMirror(self, k: int, n: int) -> int:
        total = 0
        length = 1
        while True:
            mid = (length + 1) // 2
            start = 10 ** (mid - 1)
            for i in range(start, 10 ** mid):
                pal = self.isPalindrome(i, length % 2 == 1)
                if self.palindrome(pal, k):
                    total += pal
                    n -= 1
                    if n == 0:
                        return total
            length += 1