"""
2591. Distribute Money to Maximum Children
    You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.
    You have to distribute the money according to the following rules:
    All money must be distributed.
    Everyone must receive at least 1 dollar.
    Nobody receives 4 dollars.
    Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.

    Example :
    Input: money = 20, children = 3
    Output: 1
    Explanation: 
    The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
    - 8 dollars to the first child.
    - 9 dollars to the second child. 
    - 3 dollars to the third child.
    It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
"""


class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1

        money -= children
        ans = min(money // 7, children)
        money -= 7 * ans
        remain = children - ans

        if remain == 1 and money == 3:
            ans -= 1
        elif remain == 0 and money > 0:
            ans -= 1
        return ans