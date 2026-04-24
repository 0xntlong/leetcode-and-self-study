"""
2833. Furthest Point From Origin
    You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

    In the ith move, you can choose one of the following directions:
    move to the left if moves[i] = 'L' or moves[i] = '_'
    move to the right if moves[i] = 'R' or moves[i] = '_'
    Return the distance from the origin of the furthest point you can get to after n moves.

    Example :
    Input: moves = "L_RL__R"
    Output: 3
    Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
"""

class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left, right = 0, 0
        space = 0
        for c in moves:
            if c == "L":
                left += 1
            elif c == "R":
                right += 1
            else:
                space += 1
        return abs(left - right) + space