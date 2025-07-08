/*
1751. Maximum Number of Events That Can Be Attended II
    You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
    You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
    Return the maximum sum of values that you can receive by attending events.

    Example :
    Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
    Output: 7
    Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
 */


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> starts(n);
        for (int i = 0; i < n; i++){
            starts[i] = events[i][0];
        }
        vector<int> next_idx(n);
        for (int i = 0; i < n; i++){
            auto it = upper_bound(starts.begin(), starts.end(), events[i][1]);
            next_idx[i] = it - starts.begin();
        }
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int j = 1; j <= k; j++){
            int cur = j % 2;
            int prev = (j - 1) % 2;
            for (int i = n - 1; i >= 0; i--){
                int attend = events[i][2] + dp[prev][next_idx[i]];
                int skip = dp[cur][i + 1];
                dp[cur][i] = max(attend, skip);
            }
        }
        return dp[k % 2][0];
    }
};