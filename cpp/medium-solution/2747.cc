/**
2747. Count Zero Request Servers
    You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.
    You are also given an integer x and a 0-indexed integer array queries.
    Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].
    Note that the time intervals are inclusive.
    Example :
    Input: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
    Output: [1,2]
    Explanation: 
    For queries[0]: The servers with ids 1 and 2 get requests in the duration of [5, 10]. Hence, only server 3 gets zero requests.
    For queries[1]: Only the server with id 2 gets a request in duration of [6,11]. Hence, the servers with ids 1 and 3 are the only servers that do not receive any requests during that time period.
 */



class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> ordered_queries;
        for (int i = 0; i < queries.size(); i++) {
            ordered_queries.push_back({queries[i], i});
        }
        sort(ordered_queries.begin(), ordered_queries.end());

        vector<int> frequency(n + 1, 0);
        vector<int> answer(queries.size());
        int active = 0, left = 0, right = 0;

        for (auto [q, original_index] : ordered_queries) {
            int lower = q - x;

            while (right < logs.size() && logs[right][1] <= q) {
                int server = logs[right][0];
                if (frequency[server] == 0) {
                    active++;
                }
                frequency[server]++;
                right++;
            }

            while (left < right && logs[left][1] < lower) {
                int server = logs[left][0];
                frequency[server]--;
                if (frequency[server] == 0) {
                    active--;
                }
                left++;
            }

            answer[original_index] = n - active;
        }

        return answer;
    }
};