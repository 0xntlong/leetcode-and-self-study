/*
1922. Count Good NUmbers
    A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
    For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
    Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
    A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

    Example :
    Input: n = 1
    Output: 5
    Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
*/


class Solution {
    public:
        const int MOD = 1e9 + 7;
        long long powMOD(long long x, long long num){
            if (num == 0){
                return 1;
            } else if (num % 2 == 0){
                return powMOD(x * x % MOD, num / 2);
            } else {
                return x * powMOD(x, num - 1) % MOD;
            }
        }
        int countGoodNumbers(long long n) {
            if (n % 2 == 0){
                return powMOD(20, n / 2) % MOD;
            }
            return 5 * powMOD(20, n / 2) % MOD;
        }
    };