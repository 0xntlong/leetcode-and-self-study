/*
3169. Count Days Without Meetings
    You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
    Return the count of days when the employee is available for work but no meetings are scheduled.
    Note: The meetings may overlap.
    Example :
    Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
            int res = 0;
            int end = 0;
            for (auto& start : meetings){
                if (start[0] > end){
                    res += start[0] - end - 1;
                }
                end = max(end, start[1]);
            }
            if (days > end){
                res += days - end;
            }
            return res;
        }
    };