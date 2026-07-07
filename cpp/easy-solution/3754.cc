/**
3754. Concatenate Non-Zero Digits and Multiply by Sum I
    You are given an integer n.
    Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x.
    Return an integer representing the value of x * sum.

    Example:
    Input: n = 10203004
    Output: 12340
    Explanation:
    The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
    The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
    Therefore, the answer is x * sum = 1234 * 10 = 12340.
 */



class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> arr;

        while (n > 0) {
            int d = n % 10;
            if (d > 0) {
                arr.push_back(d);
            }
            n /= 10;
        }

        long long s = 0;
        for (int d : arr) {
            s += d;
        }

        long long res = 0;
        long long tens = 1;

        for (int d : arr) {
            res += d * tens;
            tens *= 10;
        }

        return res * s;
    }
};