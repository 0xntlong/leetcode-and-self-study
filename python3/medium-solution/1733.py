"""
1733. Minimum Number of People to Teach
    On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

    You are given an integer n, an array languages, and an array friendships where:

    - There are n languages numbered 1 through n.
    - languages[i] is the set of languages the i-th user knows.
    - friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
    You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

    Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
    

    Example :
    Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
    Output: 1
    Explanation: You can either teach user 1 the second language or user 2 the first language.
"""

from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        learned = list(map(set, languages))
        visited = []
        for u, v in friendships:
            if learned[u - 1].isdisjoint(learned[v - 1]):
                visited.append((u - 1, v - 1))

        res = float("inf")
        for i in range(1, n + 1):
            hashset = set()
            for u, v in visited:
                if i not in learned[u]:
                    hashset.add(u)
                if i not in learned[v]:
                    hashset.add(v)
            res = min(res, len(hashset))
        return res