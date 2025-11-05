"""
3321. Find X-Sum of All K-Long Subarrays II
    You are given an array nums of n integers and two integers k and x.
    The x-sum of an array is calculated by the following procedure:
    Count the occurrences of all elements in the array.
    Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
    Calculate the sum of the resulting array.
    Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
    Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

    Example 1:
    Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    Output: [6,10,12]
    Explanation:
    For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
    For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

"""
from sortedcontainers import SortedList


class Solution:
    def findXSum(self, nums, k, x):
        freq = {}
        top = SortedList()
        bottom = SortedList()
        top_sum = 0
        def get_key(num):
            return (freq[num], num)
        def add_to_top(num):
            nonlocal top_sum
            top.add(get_key(num))
            top_sum += freq[num] * num
        def remove_from_top(num):
            nonlocal top_sum
            top.remove(get_key(num))
            top_sum -= freq[num] * num
        def add_to_bottom(num):
            bottom.add(get_key(num))
        def remove_from_bottom(num):
            bottom.remove(get_key(num))
        def balance():
            nonlocal top_sum
            while len(top) > x:
                key = top[0]
                top.pop(0)
                top_sum -= key[0] * key[1]
                bottom.add(key)
            while len(top) < x and bottom:
                key = bottom[-1]
                bottom.pop()
                top.add(key)
                top_sum += key[0] * key[1]
            while bottom and top and bottom[-1] > top[0]:
                bot_key = bottom[-1]
                top_key = top[0]
                bottom.pop()
                top.pop(0)
                top_sum = top_sum - top_key[0] * top_key[1] + bot_key[0] * bot_key[1]
                top.add(bot_key)
                bottom.add(top_key)
        def add_num(num):
            if num in freq:
                old_key = get_key(num)
                if old_key in top:
                    remove_from_top(num)
                    freq[num] += 1
                    add_to_top(num)
                else:
                    remove_from_bottom(num)
                    freq[num] += 1
                    add_to_bottom(num)
            else:
                freq[num] = 1
                add_to_bottom(num)
            balance()
        def remove_num(num):
            old_key = get_key(num)
            if old_key in top:
                remove_from_top(num)
                freq[num] -= 1
                if freq[num] > 0:
                    add_to_top(num)
                else:
                    del freq[num]
            else:
                remove_from_bottom(num)
                freq[num] -= 1
                if freq[num] > 0:
                    add_to_bottom(num)
                else:
                    del freq[num]
            balance()
        result = []
        for i in range(len(nums)):
            add_num(nums[i])
            if i >= k:
                remove_num(nums[i - k])
            if i >= k - 1:
                result.append(top_sum)
        return result