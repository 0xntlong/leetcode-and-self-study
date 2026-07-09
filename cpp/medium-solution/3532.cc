/**
3532. Path Existence Queries in a Graph I
    You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
    You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.
    An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.
    Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.
    
    Example :
    Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]
    Output: [true,false]
    Explanation:
    Query [0,0]: Node 0 has a trivial path to itself.
    Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
    Thus, the final answer after processing all the queries is [true, false].
 */


#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> dp(n, 0);
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                cnt++;
            }
            dp[i] = cnt;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(dp[u] == dp[v]);
        }
        return ans;
    }
};