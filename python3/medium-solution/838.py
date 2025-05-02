"""
838. Push Dominoes
    There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
    After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
    When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
    For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
    You are given a string dominoes representing the initial state where:
    dominoes[i] = 'L', if the ith domino has been pushed to the left,
    dominoes[i] = 'R', if the ith domino has been pushed to the right, and
    dominoes[i] = '.', if the ith domino has not been pushed.
    Return a string representing the final state.

    Example :
    Input: dominoes = "RR.L"
    Output: "RR.L"
    Explanation: The first domino expends no additional force on the second domino.
"""

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        vector = [0] * n
        i = 0
        for j in range(n - 1, -1, -1):
            c = dominoes[j]
            if c == 'L':
                i = n
            elif c == 'R':
                i = 0
            elif c == '.':
                if i > 0:
                    i -= 1
            vector[j] = i
        i = 0
        dominoes = list(dominoes)

        for j in range(n):
            c = dominoes[j]
            if c == 'L':
                i = 0
            elif c == 'R':
                i = n
            elif c == '.':
                if i > 0:
                    i -= 1
                if i < vector[j]:
                    dominoes[j] = 'L'
                elif i > vector[j]:
                    dominoes[j]= 'R'
        return ''.join(dominoes)