"""
3454. Separate Squares II
    You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
    Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
    Answers within 10-5 of the actual answer will be accepted.
    Note: Squares may overlap. Overlapping areas should be counted only once in this version.

    Example :
    Input: squares = [[0,0,1],[2,2,1]]
    Output: 1.00000
    Explanation:
    Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
"""

from typing import List
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        for x, y, length in squares:
            events.append((y, 1, x, x + length))
            events.append((y + length, -1, x, x + length))
        events.sort()
        active_intervals = []  
        prev_y = events[0][0]
        total_area = 0
        horizontal_slices = [] 
        def union_width(intervals):
            intervals.sort()
            total_width = 0
            rightmost = -10**30
            for left, right in intervals:
                if left > rightmost:
                    total_width += right - left
                    rightmost = right
                elif right > rightmost:
                    total_width += right - rightmost
                    rightmost = right
            return total_width
        for y, event_type, x_left, x_right in events:
            if y > prev_y and active_intervals:
                height = y - prev_y
                width = union_width(active_intervals)
                horizontal_slices.append((prev_y, height, width))
                total_area += height * width

            if event_type == 1:
                active_intervals.append((x_left, x_right))
            else:
                active_intervals.remove((x_left, x_right))
            prev_y = y
        half = total_area / 2
        accumulated = 0
        for start_y, height, width in horizontal_slices:
            slice_area = height * width
            if accumulated + slice_area >= half:
                return start_y + (half - accumulated) / width
            accumulated += slice_area
        return float(prev_y)