/*
1353. Maximum Number of Events That Can Be Attended
    You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
    You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
    Return the maximum number of events you can attend.

    Example :
    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events.
    One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.
*/



class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int,  vector<int>, greater<int>> pq;
        int n = events.size();
        int i = 0;
        int day = 1;
        int maxEvents = 0;
        while (i < n || !pq.empty()){
            if (pq.empty() && i < n){
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day){
                pq.pop();
            }
            if (!pq.empty()){
                pq.pop();
                maxEvents++;
            }
            day++;
        }
        return maxEvents;
    }
};