/**
3622. Check Divisibility by Digit Sum and Product
    You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
    The digit sum of n (the sum of its digits).
    The digit product of n (the product of its digits).
    Return true if n is divisible by this sum; otherwise, return false.
    Example :
    Input: n = 99
    Output: true
    Explanation:
    Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.
 */



class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0;
        int p = 1;

        string str = to_string(abs(n));

        for (char ch : str) {
            int d = ch - '0';
            s += d;
            p *= d;
        }

        if (n % (s + p) == 0) {
            return true;
        } else {
            return false;
        }
    }
};