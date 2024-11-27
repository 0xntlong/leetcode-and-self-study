/*
3243. Shortest Distance After Road Addition Queries I
    You are given an integer n and a 2D integer array queries.
    There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
    queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
    Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

    Example :
    Input: n = 5, queries = [[2,4],[0,2],[0,4]]
    Output: [3,2,1]
    Explanation:
    After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
    After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
    After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.
*/

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            adj[i].push_back(i + 1);
        }
        auto shortest_path = [&](){
            queue<pair<int, int>> q;
            q.push({0, 0});
            unordered_set<int> visit;
            visit.insert(0);
            while (!q.empty()){
                auto [curr, length] = q.front();
                q.pop();
                if (curr == n - 1)
                    return length;
                for (int n : adj[curr]){
                    if (visit.find(n) == visit.end()){
                        q.push({n, length + 1});
                        visit.insert(n);
                    }
                }
            }
            return -1;
        };
        vector<int> res;
        for (const auto& query : queries){
            adj[query[0]].push_back(query[1]);
            res.push_back(shortest_path());
        }
        return res;
    }
};