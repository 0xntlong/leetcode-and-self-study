/**
3658. GCD of Odd and Even Sums
    You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
    sumOdd: the sum of the smallest n positive odd numbers.
    sumEven: the sum of the smallest n positive even numbers.
    Return the GCD of sumOdd and sumEven.

    Example :
    Input: n = 4
    Output: 4
    Explanation:
    Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
    Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
    Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.
 */


#include <iostream>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if (n == 1)
            return 1;

        int sumEven = 0;
        int sumOdd = 0;

        for (int i = 1; i < n * 2; i++) {
            if (i % 2 == 0)
                sumEven += i;
            else
                sumOdd += i;
        }

        int num = min(sumEven, sumOdd);
        int num2 = max(sumEven, sumOdd);

        while (num > 0) {
            int temp = num;

            if (num2 % num == 0)
                return num;

            num = num2 % num;
            num2 = temp;
        }

        return num;
    }
};