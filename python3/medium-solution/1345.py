"""
1345. Jump Game IV
    Given an array of integers arr, you are initially positioned at the first index of the array.
    In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the array.
    Notice that you can not jump outside of the array at any time.
    Example :
    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
"""


from collections import defaultdict, deque
from typing import List

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 1:
            return 0
        graph = defaultdict(list)
        for i, val in enumerate(arr):
            graph[val].append(i)
        q = deque([0])
        visited = [False] * n
        visited[0] = True
        cnt = 0
        while q:
            for _ in range(len(q)):
                idx = q.popleft()
                if idx == n - 1:
                    return cnt
                if idx - 1 >= 0 and not visited[idx - 1]:
                    visited[idx - 1] = True
                    q.append(idx - 1)
                if idx + 1 < n and not visited[idx + 1]:
                    visited[idx + 1] = True
                    q.append(idx + 1)
                if arr[idx] in graph:
                    for nxt in graph[arr[idx]]:
                        if not visited[nxt]:
                            visited[nxt] = True
                            q.append(nxt)
                    del graph[arr[idx]]
            cnt += 1
        return -1