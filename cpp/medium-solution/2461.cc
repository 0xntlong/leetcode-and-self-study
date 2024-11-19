/*
2461. Maximum Sum of Distinct Subarrays With Length K
    You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    The length of the subarray is k, and
    All the elements of the subarray are distinct.
    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,5,4,2,9,9,9], k = 3
    Output: 15
    Explanation: The subarrays of nums with length 3 are:
    - [1,5,4] which meets the requirements and has a sum of 10.
    - [5,4,2] which meets the requirements and has a sum of 11.
    - [4,2,9] which meets the requirements and has a sum of 15.
    - [2,9,9] which does not meet the requirements because the element 9 is repeated.
    - [9,9,9] which does not meet the requirements because the element 9 is repeated.
    We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
*/


#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;
        long long curr_sum = 0;
        long long max_sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++){
            if (set.find(nums[r]) == set.end()){
                curr_sum += nums[r];
                set.insert(nums[r]);
                if ( r - l + 1 == k){
                    max_sum = max(max_sum, curr_sum);
                    curr_sum -= nums[l];
                    set.erase(nums[l]);
                    l++;
                }
            } else {
                while (nums[l] != nums[r]){
                    curr_sum -= nums[l];
                    set.erase(nums[l]);
                    l++;
                }
                l++;
            }
        }
        return max_sum;
    }
};