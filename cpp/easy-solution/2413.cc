/*
2413. Smallest Even Multiple
    Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.

    Example :
    Input: n = 5
    Output: 10
    Explanation: The smallest multiple of both 5 and 2 is 10.
*/


class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2 == 0) ? n : n * 2;
    }
};