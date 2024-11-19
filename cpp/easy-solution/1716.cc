/*
1716. Calculate Money in Leetcode Bank
    Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
    He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
    Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

    Example :
    Input: n = 4
    Output: 10
    Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        if (n < 7)
            return n * (n + 1) / 2;
        int x = 28;
        int weeks = n / 7;
        int remain = n - weeks * 7;
        int t1 = x * weeks + 7 * (weeks * (weeks - 1)) / 2;
        int t2 = (2 * weeks + remain + 1) * remain / 2;
        return t1 + t2; 
    }
};