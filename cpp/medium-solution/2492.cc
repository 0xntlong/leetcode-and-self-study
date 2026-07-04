/**
2492. Minimum Score of a Path Between Two Cities
    You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

    The score of a path between two cities is defined as the minimum distance of a road in this path.

    Return the minimum possible score of a path between cities 1 and n.

    Note:

    A path is a sequence of roads between two cities.
    It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    The test cases are generated such that there is at least one path between 1 and n.

    Example :
    Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    Output: 5
    Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
    It can be shown that no other path has less score.
 */


#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> root;
    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    int minScore(int n, vector<vector<int>>& roads) {
        root.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            root[i] = i;
        }
        for (auto& road : roads) {
            int x = road[0];
            int y = road[1];
            root[find(x)] = find(y);
        }
        int res = 1e9;
        int g1 = find(1);
        for (auto& road : roads) {
            int x = road[0];
            int d = road[2];
            if (find(x) == g1) {
                res = min(res, d);
            }
        }
        return res;
    }
};