"""
1544. Make The String Great
    Given a string s of lower and upper case English letters.
    A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
    0 <= i <= s.length - 2
    s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
    To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
    Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
    Notice that an empty string is also good.

    Example :
    Input: s = "leEeetcode"
    Output: "leetcode"
    Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
"""


class Solution:
    def makeGood(self, s: str) -> str:
        ans = []
        for i in s:
            if ans and abs(ord(ans[-1]) - ord(i)) == 32:
                ans.pop()
            else:
                ans.append(i)
        return "".join(ans)