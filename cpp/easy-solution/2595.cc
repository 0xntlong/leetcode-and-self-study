/*
2595. Number of Even and Odd Bits
    You are given a positive integer n.
    Let even denote the number of even indices in the binary representation of n with value 1.
    Let odd denote the number of odd indices in the binary representation of n with value 1.
    Note that bits are indexed from right to left in the binary representation of a number.
    Return the array [even, odd].

    Example:
    Input: n = 50
    Output: [1,2]
    Explanation:
    The binary representation of 50 is 110010.
    It contains 1 on indices 1, 4, and 5.
*/

#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> evenOddBit(int n) {
            vector<int> res(2, 0);
            int i = 0;
            while (n > 0){
                if (n & 1){
                    res[i % 2]++;
                }
                n >>= 1;
                i++;
            }
            return res;
        }
    };