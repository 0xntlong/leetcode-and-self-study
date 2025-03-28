/*
2503. Maximum Number of Points From Grid Queries
    You are given an m x n integer matrix grid and an array queries of size k.
    Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
    Otherwise, you do not get any points, and you end this process.
    After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
    Return the resulting array answer.

    Example :
    Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
    Output: [5,8,1]
    Explanation: The diagrams above show which cells we visit to get points for each query.
*/

#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<pair<int, int>> qi;
        for (int i = 0; i < k; i++){
            qi.push_back(make_pair(queries[i], i));
        }
        sort(qi.begin(), qi.end());
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq.push(make_tuple(grid[0][0], 0, 0));
        visited[0][0] = true;
        vector<int> res(k, 0);
        int count = 0;
        for (auto& q : qi){
            int limit = q.first, idx = q.second;
            while (!pq.empty() && get<0>(pq.top()) < limit){
                tuple<int, int, int> cur = pq.top();
                pq.pop();
                int wei = get<0>(cur), row = get<1>(cur), col = get<2>(cur);
                count++;
                for (auto& dir : dirs){
                    int dr = dir.first + row, dc = dir.second + col;
                    if (dr >= 0 && dr < n && dc >= 0 && dc < m && !visited[dr][dc]){
                        visited[dr][dc] = true;
                        pq.push(make_tuple(grid[dr][dc], dr, dc));
                    }
                }
            }
            res[idx] = count;
        }
        return res;
    }
};