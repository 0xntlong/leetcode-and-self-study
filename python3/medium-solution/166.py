"""
166. Fraction to Recurring Decimal
    Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
    If the fractional part is repeating, enclose the repeating part in parentheses.
    If multiple answers are possible, return any of them.
    It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

    Example:
    Input: numerator = 1, denominator = 2
    Output: "0.5"
"""


class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        sign = "-" if (numerator < 0) ^ (denominator < 0) else ''
        n, d = abs(numerator), abs(denominator)
        integer, rem = divmod(n, d)
        res = [sign + str(integer)]
        if rem == 0:
            return res[0]
        res.append('.')

        pos = {}
        while rem:
            if rem in pos:
                idx = pos[rem]
                res.insert(idx, '(')
                res.append(')')
                break
            pos[rem] = len(res)
            rem *= 10
            digit, rem =divmod(rem, d)
            res.append(str(digit))
        return ''.join(res)