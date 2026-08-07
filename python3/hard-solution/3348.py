"""
3348. Smallest Divisible Digit Product II
    You are given a string num which represents a positive integer, and an integer t.
    A number is called zero-free if none of its digits are 0.
    Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

    Example :
    Input: num = "1234", t = 256
    Output: "1488"
    Explanation:
    The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
"""



class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        temp = t

        for digit in range(2, 10):
            while temp % digit == 0:
                temp //= digit

        if temp != 1:
            return "-1"

        n = len(num)
        digits = list(num)

        remaining = [0] * (n + 1)
        remaining[0] = t

        last_valid_pos = n - 1

        for i in range(n):
            digit = int(digits[i])

            if digit == 0:
                last_valid_pos = i
                break

            common = math.gcd(remaining[i], digit)
            remaining[i + 1] = remaining[i] // common

        if remaining[n] == 1:
            return num

        for i in range(last_valid_pos, -1, -1):
            current_digit = int(digits[i])

            for new_digit in range(current_digit + 1, 10):
                digits[i] = str(new_digit)

                need = remaining[i]
                need //= math.gcd(need, new_digit)

                suffix = []

                for _ in range(n - i - 1):
                    chosen_digit = 9

                    while chosen_digit > 1 and need % chosen_digit != 0:
                        chosen_digit -= 1

                    if need % chosen_digit == 0:
                        need //= chosen_digit

                    suffix.append(str(chosen_digit))

                if need == 1:
                    suffix.reverse()

                    for j in range(i + 1, n):
                        digits[j] = suffix[j - i - 1]

                    return "".join(digits)

            digits[i] = num[i]

        factors = []
        remaining_t = t

        for digit in range(9, 1, -1):
            while remaining_t % digit == 0:
                factors.append(str(digit))
                remaining_t //= digit

        required_length = max(n + 1, len(factors))

        while len(factors) < required_length:
            factors.append("1")

        factors.reverse()

        return "".join(factors)