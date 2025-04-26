/*
2444. Count Subarrays With Fixed Bounds
    You are given an integer array nums and two integers minK and maxK.
    A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    The minimum value in the subarray is equal to minK.
    The maximum value in the subarray is equal to maxK.
    Return the number of fixed-bound subarrays.
    A subarray is a contiguous part of an array.
    Example :
    Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
    Output: 2
    Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long res = 0;
            int maxKidx = -1;
            int minKidx = -1;
            int i = 0;
            for (int x = 0; x < nums.size(); x++){
                int y = nums[x];
                if (y < minK || y > maxK){
                    i = x + 1;
                    continue;
                }
                if (y == maxK){
                    maxKidx = x;
                }
                if (y == minK){
                    minKidx = x;
                }
                res += max(min(maxKidx, minKidx) - i + 1, 0);
            }
            return res;
        }
    };