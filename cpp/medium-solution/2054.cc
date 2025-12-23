/*
2054, Two Best Non-Overlapping Events 
    You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
    Return this maximum sum.
    Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

    Example :
    Input: events = [[1,3,2],[4,5,2],[2,4,3]]
    Output: 4
    Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
*/


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>b){
            return a[0] < b[0];
        });
        vector<int> suffix(n);
        suffix[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--){
            suffix[i] = max(events[i][2], suffix[i + 1]);
        }
        int sumMax = 0;
        for (int i = 0; i < n; i++){
            int left = i + 1, right = n - 1;
            int nextEvent = -1;
            while (left <= right){
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]){
                    nextEvent = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (nextEvent != -1){
                sumMax = max(sumMax, events[i][2] + suffix[nextEvent]);
            }
            sumMax = max(sumMax, events[i][2]);
        }
        return sumMax;
    }
};



        /**
        int res = INT_MIN;
                sort(events.begin(), events.end(),
                    [](const vector<int>& a, const vector<int>& b){
                        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
                    });
                vector<int> start, suffix(events.size(), 0);
                for (int i = 0; i < events.size(); i++){
                    start.push_back(events[i][0]);
                }
                suffix.back() = events.back()[2];
                for (int i = events.size() - 2; i >= 0; i--){
                    suffix[i] = max(suffix[i + 1], events[i][2]);
                }
                for (int i = 0; i < events.size(); i++){
                    int idx = lower_bound(start.begin(), start.end(), events[i][1] + 1) - start.begin();
                    int value = events[i][2];
                    if (idx < events.size())
                        value += suffix[idx];
                    res = max(res, value);
                }
                return res;
        */