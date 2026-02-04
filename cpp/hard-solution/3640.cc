/**
3640. Trionic Array II
    You are given an integer array nums of length n.
    A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:
    nums[l...p] is strictly increasing,
    nums[p...q] is strictly decreasing,
    nums[q...r] is strictly increasing.
    Return the maximum sum of any trionic subarray in nums.

    Example :
    Input: nums = [0,-2,-1,-3,0,2,-1]
    Output: -4
    Explanation:
    Pick l = 1, p = 2, q = 3, r = 5:
    nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
    nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
    nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
    Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
 */


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size();
        long long res = -(1LL << 50);
        long long pSum = nums[0];
        for (int l = 0, p = 0, q = 0, r = 1; r < n; r++){
            pSum += nums[r];
            if (nums[r - 1] == nums[r]){
                l = r;
                pSum = nums[r];
            } else if (nums[r - 1] > nums[r]){
                if (r > 1 && nums[r - 2] < nums[r - 1]){
                    p = r - 1;
                    while (l < q){
                        pSum -= nums[l++];
                    } while (l + 1 < p && nums[l] < 0){
                        pSum -= nums[l++];
                    }
                }
            } else {
                if (r > 1 && nums[r - 2] > nums[r - 1]){
                    q = r - 1;
                }
                if (l < p && p < q)
                    res = max(res, pSum);
            }
        }
        return res;
    }
};