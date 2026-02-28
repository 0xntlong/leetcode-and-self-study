/**
1680. Concatenation of Consecutive Binary Numbers
    Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

    Example :
    Input: n = 1
    Output: 1
    Explanation: "1" in binary corresponds to the decimal value 1. 
 */



class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long res = 0;
        for (int i = 1; i <= n; i++){
            int bits = 32 - __builtin_clz(i);
            res = ((res << bits) + i) % mod;
        }
        return res;
    }
};