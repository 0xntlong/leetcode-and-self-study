/*
2338. Count the Number of Ideal Arrays
    You are given two integers n and maxValue, which are used to describe an ideal array.
    A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:
    Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
    Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
    Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.
    Example :
    Input: n = 2, maxValue = 5
    Output: 10
    Explanation: The following are the possible ideal arrays:
    - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
    - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
    - Arrays starting with the value 3 (1 array): [3,3]
    - Arrays starting with the value 4 (1 array): [4,4]
    - Arrays starting with the value 5 (1 array): [5,5]
    There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
*/


const int MOD = 1e9 + 7;
int dp[10001][14] = {1};
int cnt[10001][14] = {};
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        if (dp[1][1] == 0){
            for (int i = 1; i <= 10000; i++){
                for (int j = 0; j < 14; j++){
                    dp[i][j] = j == 0 ? 1 : (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
            }
            for (int cur = 1; cur <= 10000; cur++){
                ++cnt[cur][0];
                for (int k = 2 * cur; k <= 10000; k += cur){
                    for (int bars = 0; cnt[cur][bars]; bars++){
                        cnt[k][bars + 1] += cnt[cur][bars];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= maxValue; i++){
            for (int bars = 0; bars < min(14, n) && cnt[i][bars]; bars++){
                res = (1LL * cnt[i][bars] * dp[n - 1][bars] + res) % MOD;
            }
        }
        return res;
    }
};