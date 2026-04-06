"""
874. Walking Robot Simulation
    A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:
    -2: Turn left 90 degrees.
    -1: Turn right 90 degrees.
    1 <= k <= 9: Move forward k units, one unit at a time.
    Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.
    Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).
    Note:
    There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
    North means +Y direction.
    East means +X direction.
    South means -Y direction.
    West means -X direction.

    Example :
    Input: commands = [4,-1,3], obstacles = []
    Output: 25
    Explanation:
    The robot starts at (0, 0):
    Move north 4 units to (0, 4).
    Turn right.
    Move east 3 units to (3, 4).
    The furthest point the robot ever gets from the origin is (3, 4), which squared is 3^2 + 4^2 = 25 units away.
"""


from typing import List
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = 0
        x, y, = 0, 0
        res = 0
        hash_set = set()
        for a, b in obstacles:
            hash_set.add((a, b))

        for c in commands:
            if c == -2:
                d = (d - 1) % 4
            elif c == -1:
                d = (d + 1) % 4
            else:
                for i in range(c):
                    ox= x + dirs[d][0]
                    oy = y + dirs[d][1]
                    if (ox, oy) in hash_set:
                        break
                    res = max(res, ox**2 + oy**2)
                    x, y = ox, oy
        return res