/*
2874. Maximum Value of an Ordered Triplet II
    You are given a 0-indexed integer array nums.
    Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
    The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

    Example :
    Input: nums = [12,6,1,2,7]
    Output: 77
    Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
    It can be shown that there are no ordered triplets of indices with a value greater than 77. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long highest = 0;
            long long diff = 0;
            long long res = 0;
            for (long long num : nums){
                res = max(res, diff * num);
                diff = max(diff, highest - num);
                highest = max(highest, num);
            }
            return res;
        }
    };
    