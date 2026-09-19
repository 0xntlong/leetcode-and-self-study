"""
1401. Circle and Rectangle Overlapping
    You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
    Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

    Example :
    Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
    Output: true
    Explanation: Circle and rectangle share the point (1,0).

"""



class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x = max(x1, min(xCenter, x2))
        y = max(y1, min(yCenter, y2))
        return (xCenter - x) ** 2 + (yCenter - y) ** 2 <= radius ** 2