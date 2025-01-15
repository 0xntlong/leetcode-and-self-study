/*
2429. Minimize XOR
    Given two positive integers num1 and num2, find the positive integer x such that:
    x has the same number of set bits as num2, and
    The value x XOR num1 is minimal.
    Note that XOR is the bitwise XOR operation.
    Return the integer x. The test cases are generated such that x is uniquely determined.
    The number of set bits of an integer is the number of 1's in its binary representation.

    Example :
    Input: num1 = 3, num2 = 5
    Output: 3
    Explanation:
    The binary representations of num1 and num2 are 0011 and 0101, respectively.
    The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        int res = 0;
        for (int i = 31; i >= 0 && setBits > 0; i--){
            if (num1 & (1 << i)){
                res |= (1 << i);
                setBits--;
            }
        }
        for (int i = 0; i < 32 && setBits > 0; i++){
            if (!(res & (1 << i))){
                res |= ( 1 << i);
                setBits--;
            }
        }
        return res;
    }
};