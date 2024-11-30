/*
2097. Valid Arrangement of Pairs
    You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
    Return any valid arrangement of pairs.
    Note: The inputs will be generated such that there exists a valid arrangement of pairs.

    Example :
    Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
    Output: [[11,9],[9,4],[4,5],[5,1]]
    Explanation:
    This is a valid arrangement since endi-1 always equals starti.
    end0 = 9 == 9 = start1 
    end1 = 4 == 4 = start2
    end2 = 5 == 5 = start3
*/

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> deg;
        for (const auto& pair : pairs){
            adj[pair[0]].push_back(pair[1]);
            deg[pair[0]]++;
            deg[pair[1]]--;
        }
        int start_node = pairs[0][0];
        for (const auto& [node, degree] : deg){
            if (degree == 1){
                start_node = node;
                break;
            }
        }
        vector<int> path;
        stack<int> node_stack;
        node_stack.push(start_node);
        while (!node_stack.empty()){
            auto& curr_node = adj[node_stack.top()];
            if (curr_node.empty()){
                path.push_back(node_stack.top());
                node_stack.pop();
            } else {
                int next_node = curr_node.back();
                node_stack.push(next_node);
                curr_node.pop_back();
            }
        }
        vector<vector<int>> ans;
        int path_size = path.size();
        ans.reserve(path_size - 1);
        for (int i = path_size - 1; i > 0; i--){
            ans.push_back({path[i], path[i -1]});
        }
        return ans;
    }
};