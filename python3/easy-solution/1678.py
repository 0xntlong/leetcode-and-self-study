"""
1678. Goal Parser Interpretation
    You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
    Given the string command, return the Goal Parser's interpretation of command.

    Example 1:
    Input: command = "G()(al)"
    Output: "Goal"
    Explanation: The Goal Parser interprets the command as follows:
    G -> G
    () -> o
    (al) -> al
    The final concatenated result is "Goal".
"""


class Solution:
    def interpret(self, command: str) -> str:
        res = ""
        i = 0
        n = len(command)
        while i < n:
            if command[i] == 'G':
                res += "G"
                i += 1
            elif command[i:i+2] == "()":
                res += "o"
                i += 2
            else:
                res += "al"
                i += 4
        return res