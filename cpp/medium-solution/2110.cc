/**
2110. Number of Smooth Descent Periods of a Stock
    You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
    A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
    Return the number of smooth descent periods.

    Example :
    Input: prices = [3,2,1,4]
    Output: 7
    Explanation: There are 7 smooth descent periods:
    [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
    Note that a period with one day is a smooth descent period by the definition.
 */


#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        long long length = 1;
        long long prev = LLONG_MAX;
        for (int i : prices){
            if (prev - i == 1){
                length++;
            } else {
                res += (length * (length + 1)) / 2;
                length = 1;
            }
            prev = i;
        }
        res += (length * (length + 1)) / 2;
        return res - 1;
    }
};