/**
3740. Minimum Distance Between Three Equal Elements I
    You are given an integer array nums.
    A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
    The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
    Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.
    Example :
    Input: nums = [1,2,1,1,3]
    Output: 6
    Explanation:
    The minimum distance is achieved by the good tuple (0, 2, 3).
    (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.
 */


#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int max_val = 0;
        for (int x : nums) 
            max_val = max(max_val, x);

        vector<pair<int, int>> pos(max_val + 1, {-1, -1});

        long long res = 1LL << 32;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int last = pos[val].first;
            int second_last = pos[val].second;

            if (second_last != -1) {
                int distance = (i - second_last) * 2;
                if (distance < res) 
                    res = distance;
            }

            pos[val] = {i, last};
        }

        return (res == (1LL << 32)) ? -1 : (int)res;
    }
};