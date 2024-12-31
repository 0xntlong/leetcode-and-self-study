"""
2299. Strong Password Checker II
    A password is said to be strong if it satisfies all the following criteria:
    It has at least 8 characters.
    It contains at least one lowercase letter.
    It contains at least one uppercase letter.
    It contains at least one digit.
    It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
    It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
    Given a string password, return true if it is a strong password. Otherwise, return false.

    Example :
    Input: password = "IloveLe3tcode!"
    Output: true
    Explanation: The password meets all the requirements. Therefore, we return true.
"""


class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        n = len(password)
        if n < 8:
            return False
        lower = any(c.islower() for c in password)
        upper = any(c.isupper() for c in password)
        digit = any(c.isdigit() for c in password)
        special = any(c in "!@#$%^&*()-+" for c in password)
        adjacent = any(password[i] == password[i + 1] for i in range(n - 1))

        return lower and upper and digit and special and not adjacent