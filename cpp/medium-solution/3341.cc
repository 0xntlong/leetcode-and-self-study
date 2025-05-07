/*
3341. Find Minimum Time to Reach Last Room I
    There is a dungeon with n x m rooms arranged as a grid.
    You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
    Return the minimum time to reach the room (n - 1, m - 1).
    Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example :
    Input: moveTime = [[0,4],[4,4]]
    Output: 6
    Explanation:
    The minimum time required is 6 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    At time t == 5, move from room (1, 0) to room (1, 1) in one second.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int rows = moveTime.size();
            int cols = moveTime[0].size();
            if (rows == 1 && cols == 1){
                return 0;
            }
            set<pair<int, int>> visited;
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
            pq.push({0, 0, 0});
            visited.insert({0, 0});
            vector<pair<int, int>> ways = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            while (!pq.empty()){
                int time, row, col;
                tie(time, row, col) = pq.top();
                pq.pop();
                if (row == rows - 1 && col == cols - 1){
                    return time;
                }
                for (auto [dx, dy] : ways){
                    int nextRow = row + dx, nextCol = col + dy;
                    if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || visited.count({nextRow, nextCol}) > 0){
                        continue;
                    }
                    int nextTime = max(time, moveTime[nextRow][nextCol]) + 1;
                    pq.push({nextTime, nextRow, nextCol});
                    visited.insert({nextRow, nextCol});
                }
            }
            return -1;
        }
    };