/*
1952. Three Divisors
    Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
    An integer m is a divisor of n if there exists an integer k such that n = k * m.

    Example :
    Input: n = 2
    Output: false
    Explantion: 2 has only two divisors: 1 and 2.

*/


class Solution {
public:
    bool isThree(int n) {
        int count = 2;
        for (int i = 2; i < n; i++){
            if ( n % i == 0){
                count++;
                if (count > 3){
                    return false;
                }
            }
        }
        return count == 3;
    }
};