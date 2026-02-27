/**
3666. Minimum Operations to Equalize Binary String
    You are given a binary string s, and an integer k.
    In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.
    Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

    Example :
    Input: s = "110", k = 1
    Output: 1
    Explanation:
    There is one '0' in s.
    Since k = 1, we can flip it directly in one operation.

 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long ceil(long long x, long long y){
        return (x + y - 1) / y;
    }
    int minOperations(string s, int k) {
        int n = s.size();
        long long zero = 0;
        for (char c : s)
            if (c == '0')
                zero++;
        if (n == k){
            if (zero == 0)
                return 0;
            else if (zero == n)
                return 1;
            else return -1;
        }
        long long INF = (1LL << 60);
        long long res = INF;
        if (zero % 2 == 0){
            long long m = max(ceil(zero, k), ceil(zero, n - k));
            if (m % 2 == 1)
                m++;
            res = min(res, m);
        }
        if (zero % 2 == (k % 2)) {
            long long m = max(ceil(zero, k), ceil((long long)n - zero, n - k));
            if (m % 2 == 0) 
                m++;
            res = min(res, m);
        }
        return (res < INF) ? (int) res : -1;
    }
};