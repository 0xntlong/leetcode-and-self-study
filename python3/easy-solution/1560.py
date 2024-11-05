"""
1560. Most Visited Sector in a Circular Track
    Given an integer n and an integer array rounds. We have a circular track which consists of n sectors labeled from 1 to n. A marathon will be held on this track, the marathon consists of m rounds. The ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. For example, round 1 starts at sector rounds[0] and ends at sector rounds[1]
    Return an array of the most visited sectors sorted in ascending order.
    Notice that you circulate the track in ascending order of sector numbers in the counter-clockwise direction (See the first example).

    Example :
    Input: n = 4, rounds = [1,3,1,2]
    Output: [1,2]
    Explanation: The marathon starts at sector 1. The order of the visited sectors is as follows:
    1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
    We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.
"""


class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        start = rounds[0]
        end = rounds[-1]
        if end >= start:
            return [i for i in range(start, end + 1)]
        else:
            res = []
            for i in range(n):
                if i + 1 <= end or i + 1 >= start:
                    res.append(i + 1)
            return sorted(res)