/*
2940. Find Building Where Alice and Bob Can Meet
    You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
    If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
    You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.
    Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

    Example :
    Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
    Output: [2,5,-1,5,2]
    Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
    In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
    In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
    In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
    In the fifth query, Alice and Bob are already in the same building.  
    For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
    For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> d;
        int que = queries.size();
        vector<int> res(que, -1);
        for (int idx = 0; idx < que; idx++){
            int left = queries[idx][0];
            int right = queries[idx][1];
            if (left > right)
                swap(left, right);
            if (left == right || heights[right] > heights[left]){
                res[idx] = right;
            } else {
                int h = max(heights[left], heights[right]);
                d[right].push_back({h, idx});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (int idx = 0; idx < heights.size(); idx++){
            if (d.count(idx)){
                for (auto& q : d[idx]){
                    min_heap.push(q);
                }
            }
            while (!min_heap.empty() && heights[idx] > min_heap.top().first){
                auto [queri_h, queri_idx] = min_heap.top();
                min_heap.pop();
                res[queri_idx] = idx;
            }
        }
        return res;
    }
};