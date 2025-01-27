/*
1462. Course Schedule IV
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
    You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
    Return a boolean array answer, where answer[j] is the answer to the jth query.

    Example :
    Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    Output: [false,true]
    Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
    Course 0 is not a prerequisite of course 1, but the opposite is true.
*/


#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<100>>  path(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> deg(numCourses, 0);

        for (auto& p : prerequisites){
            int a = p[0], b = p[1];
            adj[a].push_back(b);
            path[b].set(a);
            deg[b]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (deg[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int i = q.front();
            q.pop();
            for (int j : adj[i]){
                path[j] |= path[i];
                deg[j]--;
                if (deg[j] == 0){
                    q.push(j);
                }
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries){
            int u = q[0], v = q[1];
            ans.push_back(path[v][u]);
        }
        return ans;
    }
};