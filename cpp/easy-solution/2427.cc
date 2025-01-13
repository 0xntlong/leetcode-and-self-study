/*
2427. Number of Common Factors
    Given two positive integers a and b, return the number of common factors of a and b.
    An integer x is a common factor of a and b if x divides both a and b.

    Example :
    Input: a = 12, b = 6
    Output: 4
    Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
*/

#include <algorithm>
using namespace std;
class Solution {
public:
    int commonFactors(int a, int b) {
        int common = std::min(a, b);
        int res = 0;
        for (int i = 1; i <= common + 1; i++){
            if (a % i == 0 && b % i == 0){
                res++;
            }
        }
        return res;
    }
};