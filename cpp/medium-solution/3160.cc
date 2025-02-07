/*
3160. Find the Number of Distinct Colors Among the Balls
    You are given an integer limit and a 2D array queries of size n x 2.
    There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
    Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
    Note that when answering a query, lack of a color will not be considered as a color.

    Example 1:
    Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
    Output: [1,2,2,3]
    Explanation:
    After query 0, ball 1 has color 4.
    After query 1, ball 1 has color 4, and ball 2 has color 5.
    After query 2, ball 1 has color 3, and ball 2 has color 5.
    After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            int dis = 0;
            unordered_map<int, int> freq, colors;
            vector<int> res;
            for (auto& q : queries){
                int x = q[0], y = q[1];
                if (auto it = colors.find(x); it != colors.end()){
                    int prevColor = it->second;
                    if (--freq[prevColor] == 0){
                        dis--;
                    }
                }
                colors[x] = y;
                if (++freq[y] == 1){
                    dis++;
                }
                res.push_back(dis);
            }
            return res;
        }
    };