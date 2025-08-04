"""
904. Fruit Into Baskets
    You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
    You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
    You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
    Given the integer array fruits, return the maximum number of fruits you can pick.

    Example :
    Input: fruits = [1,2,1]
    Output: 3
    Explanation: We can pick from all 3 trees.
    
"""


from typing import List

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        freq = [0] * (max(fruits) + 1)
        left = 0
        count = 0
        left = 0
        baskets = 0
        res = 0
        for right, i in enumerate(fruits):
            freq[i] += 1
            if freq[i] == 1:
                baskets += 1
            count += 1
            while baskets > 2:
                j = fruits[left]
                freq[j] -= 1
                if freq[j] == 0:
                    baskets -= 1
                left += 1
                count -= 1
            res = max(res, count)
        return res