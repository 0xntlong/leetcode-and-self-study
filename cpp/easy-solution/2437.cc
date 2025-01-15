/*
2437. Number of Valid Clock Times
    You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".
    In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.
    Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.

    Example :
    Input: time = "?5:00"
    Output: 2
    Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.

*/

#include <string>
using namespace std;
class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if (time[0] == '?' && time[1] == '?'){
            ans *= 24;
        } else {
            if (time[0] == '?'){
                if (time[1] < '4'){
                    ans *= 3;
                } else {
                    ans *= 2;
                }
            } if (time[1] == '?'){
                if (time[0] < '2'){
                    ans *= 10;
                } else {
                    ans *= 4;
                }
            }
        }
        if (time[3] == '?'){
            ans *= 6;
        }
        if (time[4] == '?'){
            ans *= 10;
        }
        return ans;
    }
};