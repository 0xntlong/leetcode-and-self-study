/**
1345. Jump Game IV
    Given an array of integers arr, you are initially positioned at the first index of the array.
    In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the array.
    Notice that you can not jump outside of the array at any time.
    Example :
    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
 */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1)
                    return cnt;
                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    q.push(idx - 1);
                }

                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    q.push(idx + 1);
                }

                if (graph.count(arr[idx])) {
                    for (int nxt : graph[arr[idx]]) {
                        if (!visited[nxt]) {
                            visited[nxt] = true;
                            q.push(nxt);
                        }
                    }
                    graph.erase(arr[idx]);
                }
            }
            cnt++;
        }
        return -1;
    }
};