/*
2395. Find Subarrays With Equal Sum
    Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
    Return true if these subarrays exist, and false otherwise.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [4,2,4]
    Output: true
    Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n - 1; j++){
                if (nums[j] + nums[j + 1] == nums[i] + nums[i + 1])
                    count++;
            }
        }
        return count >= 1;
    }
};