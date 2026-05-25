"""
1871. Jump Game VII
    You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
    i + minJump <= j <= min(i + maxJump, s.length - 1), and
    s[j] == '0'.
    Return true if you can reach index s.length - 1 in s, or false otherwise.
    Example :
    Input: s = "011010", minJump = 2, maxJump = 3
    Output: true
    Explanation:
    In the first step, move from index 0 to index 3. 
    In the second step, move from index 3 to index 5.
"""



class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        if s[-1] == "1":
            return False
        dp = [False] * n
        dp[0] = True
        reach = 0
        for i in range(1, n):
            if i - minJump >= 0:
                reach += dp[i - minJump]
            if i - maxJump - 1 >= 0:
                reach -= dp[i - maxJump - 1]
            if reach > 0 and s[i] == "0":
                dp[i] = True
        return dp[-1]