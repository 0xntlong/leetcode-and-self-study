"""
3318. Find X-Sum of All K-Long Subarrays I
    You are given an array nums of n integers and two integers k and x.
    The x-sum of an array is calculated by the following procedure:
    Count the occurrences of all elements in the array.
    Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
    Calculate the sum of the resulting array.
    Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
    Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

    Example :
    Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
    Output: [6,10,12]
    Explanation:
    For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
    For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
    For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
"""


from typing import List

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        res = []
        def count(arr):
            hash_set = {}
            for i in arr:
                if i in hash_set:
                    hash_set[i] += 1
                else:
                    hash_set[i] = 1
            return hash_set
        for i in range(len(nums) - k + 1):
            hash_set = count(nums[i : i + k])
            sorted_items = sorted(hash_set.items(), key = lambda p:(-p[1], -p[0]))
            total = 0
            for key, val in sorted_items[:x]:
                total += key * val
            res.append(total)
        return res