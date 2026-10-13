/**
3727. Maximum Alternating Sum of Squares
    You are given an integer array nums. You may rearrange the elements in any order.
    The alternating score of an array arr is defined as:
    score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
    Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
    Example :
    Input: nums = [1,2,3]
    Output: 1
    Explanation:
    A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
    The alternating score is calculated as:
    score = 22 - 12 + 32 = 4 - 1 + 9 = 12
 */

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int h = n / 2;

        vector<long long> arr;
        for (int x : nums) {
            arr.push_back(abs((long long)x));
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i < h ? -1LL : 1LL) * arr[i] * arr[i];
        }

        return ans;
    }
};