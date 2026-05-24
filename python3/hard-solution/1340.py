"""
1340. Jump Game V
    Given an array of integers arr and an integer d. In one step you can jump from index i to index:
    i + x where: i + x < arr.length and  0 < x <= d.
    i - x where: i - x >= 0 and  0 < x <= d.
    In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
    You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.
    Notice that you can not jump outside of the array at any time.

    Example :
    Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
    Output: 4
    Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
    Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
    Similarly You cannot jump from index 3 to index 2 or index 1.
"""


from typing import List

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        steps = [1 for i in range(len(arr))]
        stack = []
        n = len(arr)
        for i in range(n + 1):
            while len(stack) > 0 and (i == n or arr[stack[-1]] < arr[i]):
                pop_indices = [stack.pop()]
                while stack and arr[stack[-1]] == arr[pop_indices[0]]:
                    pop_indices.append(stack.pop())
                for j in pop_indices:
                    if i < n and i - j <= d:
                        steps[i] = max(steps[i], steps[j] + 1)
                    if len(stack) > 0 and j - stack[-1] <= d:
                        steps[stack[-1]] = max(steps[stack[-1]], steps[j] + 1)
            if i < n:
                stack.append(i)
        return max(steps)