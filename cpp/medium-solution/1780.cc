/*
1780. Check if Number is a Sum of Powers of Three
    Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
    An integer y is a power of three if there exists an integer x such that y == 3x.
    Example :
    Input: n = 12
    Output: true
    Explanation: 12 = 3^1 + 3^2
*/



class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 0){
                if (n % 3 == 2)
                    return false;
                n /= 3;
            }
            return true;
        }
    };

