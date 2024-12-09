/*
3152. Special Array II 
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
    subarray
    nums[fromi..toi] is special or not.
    Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

    Example :
    Input: nums = [3,4,1,2,6], queries = [[0,4]]
    Output: [false]
    Explanation:
    The subarray is [3,4,1,2,6]. 2 and 6 are both even.
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix(n, 0);
        vector<bool> ans;
        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2){
                prefix[i]++;
            }
        }
        for (auto& query : queries){
            int from_i = query[0], to_i = query[1];
            int not_special = prefix[to_i] - (from_i > 0 ? prefix[from_i] : 0);
            if (not_special && from_i != to_i)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};