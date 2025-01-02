/*
983. Minimum Cost For Tickets
    You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
    Train tickets are sold in three different ways:
    a 1-day pass is sold for costs[0] dollars,
    a 7-day pass is sold for costs[1] dollars, and
    a 30-day pass is sold for costs[2] dollars.
    The passes allow that many days of consecutive travel.
    For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
    Return the minimum number of dollars you need to travel every day in the given list of days.

    Example :
    Input: days = [1,4,6,7,8,20], costs = [2,7,15]
    Output: 11
    Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
    On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
    On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
    On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
    In total, you spent $11 and covered all the days of your travel.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 31, 0);
        vector<bool> day_travel(days.back(), false);
        for (int& day : days){
            day_travel[day] = true;
        }
        for (int day = days.back(); day >= days[0]; day--){
            if (!day_travel[day])
                dp[day] = dp[day + 1];
            else
                dp[day] = min(dp[day + 1] + costs[0],
                            min(dp[day + 7] + costs[1],
                                dp[day + 30] + costs[2]));
        }
        return dp[days[0]];
    }
};