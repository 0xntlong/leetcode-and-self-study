"""
3661. Maximum Walls Destroyed by Robots
    There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
    robots[i] is the position of the ith robot.
    distance[i] is the maximum distance the ith robot's bullet can travel.
    walls[j] is the position of the jth wall.
    Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.
    A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.
    Return the maximum number of unique walls that can be destroyed by the robots.
    Notes:
    A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
    Robots are not destroyed by bullets.
    Example :
    Input: robots = [4], distance = [3], walls = [1,10]
    Output: 1
    Explanation:

    robots[0] = 4 fires left with distance[0] = 3, covering [1, 4] and destroys walls[0] = 1.
    Thus, the answer is 1.
"""

from typing import List
import bisect


class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        n = len(robots)
        robots = sorted(zip(robots, distance))
        walls.sort()
        robots.append((10**18, 0))
        def count_walls(l, r):
            if l > r:
                return 0
            return bisect.bisect_right(walls, r) - bisect.bisect_left(walls, l)

        dp = [[0, 0] for _ in range(n)]
        pos, dist = robots[0]
        left_gain = count_walls(pos - dist, pos)
        right_gain = count_walls(pos, min(robots[1][0] - 1, pos + dist))
        dp[0][0] = left_gain
        dp[0][1] = right_gain

        for i in range(1, n):
            pos, dist = robots[i]
            prev_pos, prev_dist = robots[i - 1]
            left_l = max(pos - dist, prev_pos + 1)
            left_r = pos
            left_gain = count_walls(left_l, left_r)
            right_l = pos
            right_r = min(robots[i + 1][0] - 1, pos + dist)
            right_gain = count_walls(right_l, right_r)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + right_gain
            dp[i][0] = dp[i - 1][0] + left_gain
            overlap_l = left_l
            overlap_r = min(prev_pos + prev_dist, pos - 1)
            overlap = count_walls(overlap_l, overlap_r)
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + left_gain - overlap)

        return max(dp[n - 1][0], dp[n - 1][1])