/**
3741. Minimum Distance Between Three Equal Elements II
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
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(n + 1, -1);
        vector<int> second(n + 1, -1);
        int min_dist = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (second[num] != -1) {
                int dist = i - second[num];
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
            second[num] = last[num];
            last[num] = i;
        }

        return (min_dist == INT_MAX) ? -1 : 2 * min_dist;
    }
};