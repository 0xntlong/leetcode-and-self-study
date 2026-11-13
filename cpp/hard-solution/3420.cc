/**
3420. Count Non-Decreasing Subarrays After K Operations
    You are given an array nums of n integers and an integer k.
    For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.
    Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.
    Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.

    Example :
    Input: nums = [6,3,1,2,4,4], k = 7
    Output: 17
    Explanation:
    Out of all 21 possible subarrays of nums, only the subarrays [6, 3, 1], [6, 3, 1, 2], [6, 3, 1, 2, 4] and [6, 3, 1, 2, 4, 4] cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is 21 - 4 = 17.
 */

#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int right = nums.size() - 1;
        long long total_cost = 0;
        deque<pair<int, int>> q;
        long long res = 0;

        for (int left = (int)nums.size() - 1; left >= 0; left--) {
            int x = nums[left];
            int c = 1;

            while (!q.empty() && q.front().first < x) {
                auto [value, count] = q.front();
                q.pop_front();

                total_cost += 1LL * (x - value) * count;
                c += count;
            }

            q.push_front({x, c});

            while (total_cost > k) {
                auto [value, count] = q.back();
                q.pop_back();

                total_cost -= 1LL * value - nums[right];
                right--;

                if (count > 1) {
                    q.push_back({value, count - 1});
                }
            }

            res += right - left + 1;
        }

        return res;
    }
};