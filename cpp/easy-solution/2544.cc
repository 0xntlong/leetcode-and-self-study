/*
2544. Alternating Digit Sum
    You are given a positive integer n. Each digit of n has a sign according to the following rules:
    The most significant digit is assigned a positive sign.
    Each other digit has an opposite sign to its adjacent digits.
    Return the sum of all digits with their corresponding sign.

    Example :
    Input: n = 521
    Output: 4
    Explanation: (+5) + (-2) + (+1) = 4.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int alternateDigitSum(int n) {
            std::string nums = std::to_string(n);
            int res = 0, i = 1;
            for (char c : nums){
                res += (c - '0') * i;
                i *= -1;
            }
            return res;
        }
    };