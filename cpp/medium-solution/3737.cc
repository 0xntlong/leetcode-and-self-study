/**
3737. Count Subarrays With Majority Element I
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



class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int balance = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int res = 0;
        int curr = 0;
        for (int x : nums) {
            if (x == target) {
                curr += cnt[balance];
                balance++;
            } else {
                balance--;
                curr -= cnt[balance];
            }
            cnt[balance]++;
            res += curr;
        }
        return res;
    }
};