"""
2071. Maximum Number of Tasks You Can Assign
    You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
    Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
    Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
    Example :
    Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
    Output: 3
    Explanation:
    We can assign the magical pill and tasks as follows:
    - Give the magical pill to worker 0.
    - Assign worker 0 to task 2 (0 + 1 >= 1)
    - Assign worker 1 to task 1 (3 >= 2)
    - Assign worker 2 to task 0 (3 >= 3)
"""

from collections import deque
from typing import List
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort(reverse = True)
        def can_used(k : int) -> bool:
            cnt = 0
            p = pills
            q = deque[int]()
            for i in range(k - 1, -1, -1):
                if len(q) == 0 and workers[cnt] >= tasks[i]:
                    cnt += 1
                    continue
                if len(q) > 0 and q[0] >= tasks[i]:
                    q.popleft()
                    continue
                while cnt < k and workers[cnt] + strength >= tasks[i]:
                    q.append(workers[cnt])
                    cnt += 1
                if len(q) > 0 and p > 0:
                    q.pop()
                    p -= 1
                    continue
                return False
            return True
        left = 0
        right = min(len(tasks), len(workers))
        used = 0
        while left <= right:
            mid = (left + right) // 2
            if can_used(mid):
                used = mid
                left = mid + 1
            else:
                right = mid - 1
        return used