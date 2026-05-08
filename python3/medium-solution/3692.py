"""
3629. Minimum Jumps to Reach End via Prime Teleportation
    You are given an integer array nums of length n.
    You start at index 0, and your goal is to reach index n - 1.
    From any index i, you may perform one of the following operations:
    Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
    Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
    Return the minimum number of jumps required to reach index n - 1.
    Example :
    Input: nums = [1,2,4,6]
    Output: 2
    Explanation:
    One optimal sequence of jumps is:
    Start at index i = 0. Take an adjacent step to index 1.
    At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.

"""

from typing import List

from collections import defaultdict, deque

class Solution:
    def minJumps(self, nums: List[int]) -> int:
        topPrime = int(1e5) + 1
        port = defaultdict(list)
        n = len(nums)
        for i, num in enumerate(nums):
            d = 2
            tmp = num
            while d * d <= tmp:
                if tmp % d == 0:
                    port[d].append(i)
                    while tmp % d == 0:
                        tmp //= d
                d += 1
            if tmp > 1:
                port[tmp].append(i)
                
        visited = [False] * n
        q = deque()
        q.append(0)
        steps = 0
        while q:
            for _ in range(len(q)):
                i = q.popleft()
                num = nums[i]
                if visited[i]:
                    continue
                visited[i] = True
                if i == n - 1:
                    return steps
                if num in port:
                    for nei in port[num]:
                        q.append(nei)
                    del port[num]
                if i + 1 < n:
                    q.append(i + 1)
                if i - 1 >= 0:
                    q.append(i - 1)
            steps += 1
        return steps