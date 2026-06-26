/**
3739. Count Subarrays With Majority Element II
    You are given an integer array nums and an integer target.
    Return the number of subarrays of nums in which target is the majority element.
    The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

    Example :
    Input: nums = [1,2,2,3], target = 2
    Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
    nums[1..1] = [2]
    nums[2..2] = [2]
    nums[1..2] = [2,2]
    nums[0..2] = [1,2,2]
    nums[1..3] = [2,2,3]
    So there are 5 such subarrays.
 */


#include <vector>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 1, 0);
        freq[n] = 1;
        int idx = n;
        long long res = 0;
        long long pref = 0;
        for (int x : nums) {
            if (x == target) {
                pref += freq[idx];
                idx++;
            } else {
                idx--;
                pref -= freq[idx];
            }
            freq[idx]++;
            res += pref;
        }
        return res;
    }
};