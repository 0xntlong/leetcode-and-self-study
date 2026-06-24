/**
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
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    vector<vector<long long>> multiplyMatrices(vector<vector<long long>>& matrixA, vector<vector<long long>>& matrixB) {
        int size = matrixA.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int row = 0; row < size; row++) {
            for (int mid = 0; mid < size; mid++) {
                if (matrixA[row][mid] == 0) 
                    continue;
                for (int col = 0; col < size; col++) {
                    result[row][col] = (
                        result[row][col] + matrixA[row][mid] * matrixB[mid][col]
                    ) % MOD;
                }
            }
        }
        return result;
    }

    vector<vector<long long>> matrixPower(vector<vector<long long>> matrix, int power) {
        int size = matrix.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int row = 0; row < size; row++) {
            result[row][row] = 1;
        }
        while (power > 0) {
            if (power & 1) 
                result = multiplyMatrices(result, matrix);
            matrix = multiplyMatrices(matrix, matrix);
            power >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int valueCount = r - l + 1;
        vector<long long> initialDp(valueCount);
        for (int i = 0; i < valueCount; i++) {
            initialDp[i] = i;
        }
        vector<vector<long long>> transitionMatrix(valueCount, vector<long long>(valueCount, 0));
        for (int row = 1; row < valueCount; row++) {
            for (int col = valueCount - row; col < valueCount; col++) {
                transitionMatrix[row][col] = 1;
            }
        }
        vector<vector<long long>> poweredTransition = matrixPower(transitionMatrix, n - 2);
        long long answer = 0;
        for (int row = 0; row < valueCount; row++) {
            for (int col = 0; col < valueCount; col++) {
                answer = (answer + poweredTransition[row][col] * initialDp[col]) % MOD;
            }
        }
        return answer * 2 % MOD;
    }
};