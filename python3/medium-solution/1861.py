"""
1861. Rotating the Box
    You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:
    A stone '#'
    A stationary obstacle '*'
    Empty '.'
    The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
    It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
    Return an n x m matrix representing the box after the rotation described above.

    Example :
    Input: box = [["#",".","#"]]
    Output: [["."],
            ["#"],
            ["#"]]
"""

from typing import List
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        rows, cols = len(box), len(box[0])
        rotate = [["."] * rows for _ in range(cols)]
        for col, row in enumerate(box):
            end_point = cols - 1
            for c in range(cols -1, -1, -1):
                if row[c] == "#":
                    rotate[end_point][rows - col - 1] = "#"
                    end_point -= 1
                elif row[c] == "*":
                    rotate[c][rows - col - 1] = "*"
                    end_point = c - 1
        return rotate