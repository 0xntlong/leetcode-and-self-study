"""
2106. Maximum Fruits Harvested After at Most K Steps   
    Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.
    You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.
    Return the maximum total number of fruits you can harvest.

    Example :
    Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
    Output: 9
    Explanation: 
    The optimal way is to:
    - Move right to position 6 and harvest 3 fruits
    - Move right to position 8 and harvest 6 fruits
    You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
"""



from typing import List
import bisect

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        res = 0
        left = bisect.bisect_left(fruits, [startPos - k, float("-inf")])
        right = bisect.bisect_right(fruits, [startPos, float("-inf")])
        
        cur_sum = sum([fruits[i][1] for i in range(left, right)])

        res = cur_sum
        
        for i in range(right, len(fruits)):
            cur_sum += fruits[i][1]
            r = fruits[i][0]
            if r - startPos > k:
                break
            while min(abs(r - startPos), abs(startPos - fruits[left][0])) + r - fruits[left][0] > k:
                cur_sum -= fruits[left][1]
                left += 1
            res = max(res, cur_sum)
        return res