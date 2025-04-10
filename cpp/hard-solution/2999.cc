/*
2999. Count the Number of Powerful Integers
    You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.
    A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.
    Return the total number of powerful integers in the range [start..finish].
    A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.

    Example :
    Input: start = 1, finish = 6000, limit = 4, s = "124"
    Output: 5
    Explanation: The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit <= 4, and "124" as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
    It can be shown that there are only 5 powerful integers in this range.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long tens[17];
        long long powB[17];
        void computeTens(){
            if (tens[0] == 1){
                return;
            }
            tens[0] = 1;
            for (int i = 1; i < 17; i++){
                tens[i] = tens[i - 1] * 10LL;
            }
        }
        void computePowB(int B){
            powB[0] = 1;
            for (int i = 1; i < 17; i++){
                powB[i] = powB[i - 1] * B;
            }
        }
        long long cnt(long long num, long long suffix, int ds ,int limit){
            if (num < suffix)
                return 0;
            long long x0 = num, rem = x0 % tens[ds];
            x0 /= tens[ds];
            int d = lower_bound(tens, tens + 17, x0) - tens;
            long long cnt = 0;
            for (int i = d; i >= 0; i--){
                auto [q, r] = ldiv(x0, tens[i]);
                if (q > limit){
                    cnt += powB[i + 1];
                    return cnt;
                }
                cnt += powB[i] * q;
                x0 -= q * tens[i];
            }
            return cnt + (rem >= suffix);
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            computeTens();
            computePowB(limit + 1);
            long long prefix = stoll(s);
            int S = s.size(), sStart = log10(start) + 1, sFinish = log10(finish) + 1;
            return cnt(finish, prefix, S, limit) - cnt(start - 1, prefix, S, limit);
        }
    };