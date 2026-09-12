"""
3414. Maximum Score of Non-overlapping Intervals
    You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.
    Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.
    Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.
    Example:
    Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
    Output: [2,3]
    Explanation:
    You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.
"""

from bisect import bisect_left
from typing import List

class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        intervals_with_index = []

        for i, (left, right, weight) in enumerate(intervals):
            intervals_with_index.append((right, left, weight, i))

        intervals_with_index.sort()

        n = len(intervals_with_index)
        right_ends = [item[0] for item in intervals_with_index]

        previous = [(0, ()) for _ in range(n + 1)]

        def choose_better(option1, option2):
            if option1[0] > option2[0]:
                return option1

            if option2[0] > option1[0]:
                return option2

            if option1[1] < option2[1]:
                return option1

            return option2

        for selected_count in range(1, 5):
            current = [(0, ()) for _ in range(n + 1)]

            for i in range(1, n + 1):
                right, left, weight, original_index = intervals_with_index[i - 1]
                skip = current[i - 1]
                previous_count = bisect_left(right_ends, left, 0, i - 1)
                previous_score, previous_indices = previous[previous_count]
                new_indices = list(previous_indices)
                new_indices.append(original_index)
                new_indices.sort()

                take = (previous_score + weight, tuple(new_indices))
                current[i] = choose_better(skip, take)

            previous = current

        return list(previous[n][1])