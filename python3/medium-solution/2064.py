"""
2064. Minimized Maximum of Products Distributed to Any Store
    You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
    You need to distribute all products to the retail stores following these rules:
    A store can only be given at most one product type but can be given any amount of it.
    After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
    Return the minimum possible x.

    Example :
    Input: n = 6, quantities = [11,6]
    Output: 3
    Explanation: One optimal way is:
    - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
    - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
    The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
"""

from typing import List
class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def can_distribute(amount):
            stores = 0
            for q in quantities:
                stores += (q + amount - 1) // amount
            return stores <= n
        left , right = 1, max(quantities)
        result = 0
        while left <= right:
            mid = (left + right) // 2
            if can_distribute(mid):
                result = mid
                right = mid - 1
            else :
                left = mid + 1
        return result