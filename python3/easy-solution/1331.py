"""
1331. Rank Transform of an Array
    Given an array of integers arr, replace each element with its rank.
    The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.

    Example 
    Input: arr = [40,10,20,30]
    Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
 """


from typing import List


class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        List = {}
        sortArray = sorted(arr)
        rank = 1
        for i in sortArray:
            if i not in List:
                List[i] = rank
                rank += 1
        return [List[i] for i in arr]