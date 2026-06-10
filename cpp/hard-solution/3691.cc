/**
3691. Maximum Total Subarray Value II
    You are given an integer array nums of length n and an integer k.
    You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.
    The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
    The total value is the sum of the values of all chosen subarrays.
    Return the maximum possible total value you can achieve.

    Example :
    Input: nums = [1,3,2], k = 2
    Output: 4
    Explanation:
    One optimal approach is:
    Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
    Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
    Adding these gives 2 + 2 = 4.
 */


#include <vector>
#include <queue>
using namespace std;

class Solution {
    int size;
    vector<int> seg_max, seg_min;

    pair<int, int> query(int l, int r) {
        int mx = 0, mn = 2e9;
        for (l += size, r += size; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) { mx = max(mx, seg_max[l]); mn = min(mn, seg_min[l]); l++; }
            if (r % 2 == 0) { mx = max(mx, seg_max[r]); mn = min(mn, seg_min[r]); r--; }
        }
        return {mx, mn};
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        size = 1; while (size < n) size *= 2;
        seg_max.assign(2 * size, 0);
        seg_min.assign(2 * size, 2e9);
        for (int i = 0; i < n; i++) { seg_max[size + i] = seg_min[size + i] = nums[i]; }
        for (int i = size - 1; i > 0; i--) {
            seg_max[i] = max(seg_max[2 * i], seg_max[2 * i + 1]);
            seg_min[i] = min(seg_min[2 * i], seg_min[2 * i + 1]);
        }
        priority_queue<pair<int, pair<int, int>>> heap;
        for (int l = 0; l < n; l++) {
            auto res = query(l, n - 1);
            heap.push({res.first - res.second, {l, n - 1}});
        }
        long long ans = 0;
        while (k-- && !heap.empty()) {
            auto top = heap.top(); heap.pop();
            ans += top.first;
            int l = top.second.first, r = top.second.second;
            if (r > l) {
                auto res = query(l, r - 1);
                heap.push({res.first - res.second, {l, r - 1}});
            }
        }
        return ans;
    }
};