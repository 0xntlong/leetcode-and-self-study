"""
1039. Minimum Score Triangulation of Polygon
    You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
    Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
    You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
    Return the minimum possible score that you can achieve with some triangulation of the polygon.

    Example :
    Input: values = [1,2,3]
    Output: 6
    Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
"""



from typing import List
import math
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        """
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        for d in range(3, n + 1):
            for i in range(n - d + 1):
                j = i + d - 1
                best = float('inf')
                for k in range(i + 1, j):
                    best = min(best, dp[i][k] + dp[k][j] + values[i] * values[k] * values[j])
                dp[i][j] = best
        return dp[0][n - 1]
        """
        n = len(values)
        if n == 3:
            return values[0] * values[1] * values[2]
        
        dp = [[0] * n for _ in range(n - 1)]
        
        for d in range(2, n):
            for i in range(n - d):
                j = i + d
                e = values[i] * values[j]
                best = math.inf
                for k in range(i + 1, j):
                    cand = e * values[k] + dp[i][k] + dp[k][j]
                    if cand < best:
                        best = cand
                dp[i][j] = best
        return dp[0][n - 1]