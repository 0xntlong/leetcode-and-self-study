"""
1306. Jump Game III
    Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
    Notice that you can not jump outside of the array at any time.
    Example :
    Input: arr = [4,2,3,0,3,1,2], start = 5
    Output: true
    Explanation: 
    All possible ways to reach at index 3 with value 0 are: 
    index 5 -> index 4 -> index 1 -> index 3 
    index 5 -> index 6 -> index 4 -> index 1 -> index 3 
"""

from collections import deque
from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        q = deque([start])
        visited = [False] * n
        visited[start] = True

        while q:
            node = q.popleft()
            if arr[node] == 0:
                return True
            l, r = node - arr[node], node + arr[node]
            if l >= 0 and not visited[l]:
                q.append(l)
                visited[l] = True
            if r < n and not visited[r]:
                q.append(r)
                visited[r] = True
        return False