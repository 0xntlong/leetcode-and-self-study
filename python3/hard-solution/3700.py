"""
3700. Number of ZigZag Arrays II
    You are given three integers n, l, and r.
    A ZigZag array of length n is defined as follows:
    Each element lies in the range [l, r].
    No two adjacent elements are equal.
    No three consecutive elements form a strictly increasing or strictly decreasing sequence.
    Return the total number of valid ZigZag arrays.
    Since the answer may be large, return it modulo 109 + 7.
    A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
    A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
    Example :
    Input: n = 3, l = 4, r = 5
    Output: 2
    Explanation:
    There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:
    [4, 5, 4]
    [5, 4, 5]
"""



class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        value_count = r - l + 1
        initial_dp = list(range(value_count))
        transition_matrix = [[0] * value_count for _ in range(value_count)]
        for row in range(1, value_count):
            for col in range(value_count - row, value_count):
                transition_matrix[row][col] = 1
        def multiply_matrices(matrix_a, matrix_b):
            size = len(matrix_a)
            result = [[0] * size for _ in range(size)]
            for row in range(size):
                for mid in range(size):
                    if matrix_a[row][mid] == 0:
                        continue

                    for col in range(size):
                        result[row][col] = (result[row][col]+ matrix_a[row][mid] * matrix_b[mid][col]) % MOD

            return result

        def matrix_power(matrix, power):
            size = len(matrix)
            result = [[1 if row == col else 0 for col in range(size)] for row in range (size)]
            while power:
                if power & 1:
                    result = multiply_matrices(result, matrix)
                matrix = multiply_matrices(matrix, matrix)
                power >>= 1
            return result
        powered_transition = matrix_power(transition_matrix, n - 2)
        answer = 0

        for row in range(value_count):
            for col in range(value_count):
                answer = (answer + powered_transition[row][col] * initial_dp[col]) % MOD
        return (answer * 2) % MOD