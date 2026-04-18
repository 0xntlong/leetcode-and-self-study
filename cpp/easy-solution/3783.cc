/**
3783. Mirror Distance of an Integer
    You are given an integer n.
    Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.
    Return an integer denoting the mirror distance of n​​​​​​​.
    abs(x) denotes the absolute value of x.

    Example :
    Input: n = 25
    Output: 27
    Explanation:
    reverse(25) = 52.
    Thus, the answer is abs(25 - 52) = 27.
 */

#include <cmath>
using namespace std;
class Solution {
public:
    int mirrorDistance(int n) {
        int reversion = 0;
        int x = n;
        while (x > 0) {
            int r = x % 10;
            x /= 10;
            reversion = reversion * 10 + r;
        }

        return abs(reversion - n);
    }
};