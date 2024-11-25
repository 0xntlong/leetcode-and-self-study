"""
1773. Count Items Matching a Rule
    You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.
    The ith item is said to match the rule if one of the following is true:
    ruleKey == "type" and ruleValue == typei.
    ruleKey == "color" and ruleValue == colori.
    ruleKey == "name" and ruleValue == namei.
    Return the number of items that match the given rule.

    Example :
    Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
    Output: 1
    Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
"""

from typing import List
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        count, i, j = 0, 0, 0
        size = len(items)
        if ruleKey == "type":
            j = 0
            for i in range(size):
                if items[i][j] == ruleValue:
                    count += 1
        if ruleKey == "color":
            j = 1
            for i in range(size):
                if items[i][j] == ruleValue:
                    count += 1
        if ruleKey == "name":
            j = 2
            for i in range(size):
                if items[i][j] == ruleValue:
                    count += 1

        return count