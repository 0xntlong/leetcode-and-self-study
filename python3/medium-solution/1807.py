"""
1807. Evaluate the Bracket Pairs of a String
    You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.

    For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
    You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.

    You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:

    Replace keyi and the bracket pair with the key's corresponding valuei.
    If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
    Each key will appear at most once in your knowledge. There will not be any nested brackets in s.

    Return the resulting string after evaluating all of the bracket pairs.

    

    Example 1:

    Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
    Output: "bobistwoyearsold"
    Explanation:
    The key "name" has a value of "bob", so replace "(name)" with "bob".
    The key "age" has a value of "two", so replace "(age)" with "two".
"""


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        d = dict(knowledge)
        ans = []
        start = -1

        for i, c in enumerate(s):
            if c == "(":
                start = i

            elif c == ")":
                ans.append(d.get(s[start + 1:i], "?"))
                start = -1

            elif start < 0:
                ans.append(c)

        return "".join(ans)