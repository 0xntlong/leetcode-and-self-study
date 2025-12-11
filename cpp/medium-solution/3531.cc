/**
3531. Count Covered Buildings
    You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
    A building is covered if there is at least one building in all four directions: left, right, above, and below.
    Return the number of covered buildings.

    Example :
    Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    Output: 1
    Explanation:
    Only building [2,2] is covered as it has at least one building:
    above ([1,2])
    below ([3,2])
    left ([2,1])
    right ([2,3])
    Thus, the count of covered buildings is 1.
 */


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> dict_x, dict_y;
        for (auto& build : buildings) {
            int x = build[0], y = build[1];
            dict_x[x].push_back(y);
            dict_y[y].push_back(x);
        }
        for (auto& entry : dict_x) {
            sort(entry.second.begin(), entry.second.end());
        }
        for (auto& entry : dict_y) {
            sort(entry.second.begin(), entry.second.end());
        }
        int res = 0;
        for (auto& build : buildings) {
            int x = build[0], y = build[1];
            vector<int>& ox = dict_x[x];
            vector<int>& oy = dict_y[y];
            if (oy[0] < x && oy[oy.size() - 1] > x && ox[0] < y && ox[ox.size() - 1] > y){
                res++;
            }
        }
        return res;
    }
};