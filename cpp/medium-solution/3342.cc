/*
3342. Find Minimum Time to Reach Last Room II
    There is a dungeon with n x m rooms arranged as a grid.
    You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
    Return the minimum time to reach the room (n - 1, m - 1).
    Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example :
    Input: moveTime = [[0,4],[4,4]]
    Output: 7
    Explanation:
    The minimum time required is 7 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;
 class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size();
            int m = moveTime[0].size();
            int INF = INT_MAX;
            vector<vector<int>> dp(n, vector<int>(m, INF));
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
            heap.push({0, 0, 0});
            moveTime[0][0] = 0;
            vector<pair<int, int>> ways = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            while(!heap.empty()){
                int time = heap.top()[0];
                int row = heap.top()[1];
                int col = heap.top()[2];
                heap.pop();
                if (time >= dp[row][col]){
                    continue;
                }
                if (row == n - 1 && col == m - 1){
                    return time;
                }
                dp[row][col] = time;
                for (auto& move : ways){
                    int nextRow = row + move.first;
                    int nextCol = col + move.second;
                    if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && dp[nextRow][nextCol] == INF){
                        int cost = (row + col) % 2 + 1;
                        int count = max(moveTime[nextRow][nextCol], time);
                        int nextTime = count + cost;
                        heap.push({nextTime, nextRow, nextCol});
                    }
                }
            }
            return -1;
        }
    };