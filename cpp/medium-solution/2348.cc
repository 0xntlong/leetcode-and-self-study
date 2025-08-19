/**
2348. Number of Zero-Filled Subarrays
    Given an integer array nums, return the number of subarrays filled with 0.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :

    Input: nums = [1,3,0,0,2,0,0,4]
    Output: 6
    Explanation: 
    There are 4 occurrences of [0] as a subarray.
    There are 2 occurrences of [0,0] as a subarray.
    There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
 */

#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long size = 0;
        long long total = 0;
        for (int n : nums){
            if (n == 0){
                size += 1;
            } else {
                if (size != 0){
                    total += (size * (size + 1)) / 2;
                    size = 0;
                }
            }
        }
        if (size != 0){
            total += (size * (size + 1)) / 2;
        }
        return total;
    }
};