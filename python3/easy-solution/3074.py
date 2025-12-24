"""
3074. Apple Redistribution into Boxes
    You are given an array apple of size n and an array capacity of size m.
    There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
    Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
    Note that, apples from the same pack can be distributed into different boxes.
    
    Example :
    Input: apple = [1,3,2], capacity = [4,3,1,5,2]
    Output: 2
    Explanation: We will use boxes with capacities 4 and 5.
    It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.

"""


from typing import List
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apple = sum(apple)
        capacity.sort(reverse = True)
        capacities = 0
        cnt = 0
        for cap in capacity:
            capacities += cap
            cnt += 1
            if capacities >= total_apple:
                return cnt
        return cnt

            