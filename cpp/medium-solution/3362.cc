/*
3362. Zero Array Transformation III
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
    Each queries[i] represents the following action on nums:
    Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.
    Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

    Example :
    Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
    Output: 1
    Explanation:
    After removing queries[2], nums can still be converted to a zero array.
    Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
    Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 */


class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;
        for (auto& q : queries){
            int l = q[0], r = q[1];
            edges[l].push_back(r);
        }
        vector<int> lines(n + 1, 0);
        priority_queue<int> heap;
        int cur = 0;
        for (int num_idx = 0; num_idx < n; num_idx++){
            if (edges.count(num_idx)){
                for (int end : edges[num_idx]){
                    heap.push(end);
                }
            }
            cur += lines[num_idx];
            while (cur < nums[num_idx]){
                if (heap.empty() || heap.top() < num_idx){
                    return -1;
                }
                int end = heap.top();
                heap.pop();
                cur++;
                if (end + 1 < lines.size()){
                    lines[end + 1]--;
                }
            }
        }
        return heap.size();
    }
};