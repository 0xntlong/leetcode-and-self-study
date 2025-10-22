/**
3347. Maximum Frequency of an Element After Performing Operations II
    You are given an integer array nums and two integers k and numOperations.
    You must perform an operation numOperations times on nums, where in each operation you:
    Select an index i that was not selected in any previous operations.
    Add an integer in the range [-k, k] to nums[i].
    Return the maximum possible frequency of any element in nums after performing the operations.

    Example :
    Input: nums = [1,4,5], k = 1, numOperations = 2
    Output: 2
    Explanation:
    We can achieve a maximum frequency of two by:
    Adding 0 to nums[1], after which nums becomes [1, 4, 5].
    Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 */

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;
        for (auto& [key, val] : freq) {
            int low = key - k;
            int high = key + k;
            int left = lower_bound(nums.begin(), nums.end(), low) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), high) - nums.begin();
            int in_range = right - left;
            int visited = in_range - val;
            int min_loop = min(visited, numOperations);
            ans = max(ans, val + min_loop);
        }

        int l = 0;
        for (int r = 0; r < n; r++) {
            while (l <= r && nums[r] - nums[l] > 2 * k) {
                l++;
            }
            int w = r - l + 1;
            ans = max(ans, min(w, numOperations));
        }

        return ans;
    }
};