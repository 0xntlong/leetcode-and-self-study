"""
2747. Count Zero Request Servers
    You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.
    You are also given an integer x and a 0-indexed integer array queries.
    Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].
    Note that the time intervals are inclusive.
    Example :
    Input: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
    Output: [1,2]
    Explanation: 
    For queries[0]: The servers with ids 1 and 2 get requests in the duration of [5, 10]. Hence, only server 3 gets zero requests.
    For queries[1]: Only the server with id 2 gets a request in duration of [6,11]. Hence, the servers with ids 1 and 3 are the only servers that do not receive any requests during that time period.
"""

from typing import List

class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda log: log[1])
        ordered_queries = sorted((q, i) for i, q in enumerate(queries))

        frequency = [0] * (n + 1)
        active = 0
        left = right = 0
        answer = [0] * len(queries)

        for q, original_index in ordered_queries:
            lower = q - x

            while right < len(logs) and logs[right][1] <= q:
                server = logs[right][0]
                if frequency[server] == 0:
                    active += 1
                frequency[server] += 1
                right += 1

            while left < right and logs[left][1] < lower:
                server = logs[left][0]
                frequency[server] -= 1
                if frequency[server] == 0:
                    active -= 1
                left += 1

            answer[original_index] = n - active

        return answer