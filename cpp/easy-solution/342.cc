/**
342. Power of Four
    Given an integer n, return true if it is a power of four. Otherwise, return false.
    An integer n is a power of four, if there exists an integer x such that n == 4x.

    Example :

    Input: n = 16
    Output: true
 */


class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        long long temp = 1;
        int i = 0;
        while (true){
            if (temp == n){
                return true;
            } else if (temp > n){
                return false;
            }
            temp *= 4;
            i++;
        }
    }
};