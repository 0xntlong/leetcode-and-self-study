/*
368. Largest Divisible Subset
    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.
    Example :
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
*/

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            const int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<int> len(n, 1), prev(n, -1);
            int maxLen = 0, maxIdx = -1;
            for (int i = 0; i < n; i++){
                for (int j = i + 1; j < n; j++){
                    if (nums[j] % nums[i] == 0 && len[j] < len[i] + 1){
                        len[j] = len[i] + 1;
                        prev[j] = i;
                    }
                }
                if (len[i] > maxLen){
                    maxLen = len[i];
                    maxIdx = i;
                }
            }
            vector<int> ans;
            for (int j = maxIdx; j != -1; j = prev[j]){
                ans.push_back(nums[j]);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };