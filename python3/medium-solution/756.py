"""
756. Pyramid Transition Matrix
    You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
    To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
    For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
    You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
    Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

    Example :
    Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
    Output: true
    Explanation: The allowed triangular patterns are shown on the right.
    Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
    There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.

"""


from typing import List

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        mapping = {}
        for triple in allowed:
            key = triple[:2]
            mapping.setdefault(key, []).append(triple[2])

        memo = {}
        def DFS(row):
            if row in memo:
                return memo[row]
            if len(row) == 1:
                memo[row] = True
                return True
            n = len(row)
            for i in range(n - 1):
                if row[i : i + 2] not in mapping:
                    memo[row] = False
                    return False
            
            def helper(i, curr):
                if i == n - 1:
                    return DFS(curr)
                pair = row[i : i + 2]
                for c in mapping.get(pair, []):
                    if helper(i + 1, curr + c):
                        return True
                return False
            memo[row] = helper(0, "")
            return memo[row]
        return DFS(bottom)