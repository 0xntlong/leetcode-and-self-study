/**
3013. Divide an Array Into Subarrays With Minimum Cost II
    You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.
    The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
    You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.
    Return the minimum possible sum of the cost of these subarrays.
    Example :
    Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
    Output: 5
    Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
    It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        long long base = nums[0];
        int kSmall = k - 1;

        vector<int> a(nums.begin() + 1, nums.end());
        int m = (int)a.size();

        multiset<int> small, big;
        long long sumSmall = 0;

        auto rebalance = [&]() {
            while ((int)small.size() > kSmall) {
                auto it = prev(small.end());
                sumSmall -= *it;
                big.insert(*it);
                small.erase(it);
            }
            while ((int)small.size() < kSmall && !big.empty()) {
                auto it = big.begin();
                sumSmall += *it;
                small.insert(*it);
                big.erase(it);
            }
        };

        auto add = [&](int x) {
            if (small.empty() || x <= *prev(small.end())) {
                small.insert(x);
                sumSmall += x;
            } else {
                big.insert(x);
            }
            rebalance();
        };

        auto removeVal = [&](int x) {
            auto itS = small.find(x);
            if (itS != small.end()) {
                sumSmall -= x;
                small.erase(itS);
            } else {
                auto itB = big.find(x);
                if (itB != big.end()) 
                    big.erase(itB);
            }
            rebalance();
        };

        for (int i = 0; i <= dist && i < m; i++) add(a[i]);

        long long res = base + sumSmall;

        int l = 0;
        int r = dist;

        while (r + 1 < m) {
            removeVal(a[l]);
            l++;
            r++;
            add(a[r]);
            res = min(res, base + sumSmall);
        }

        return res;
    }
};