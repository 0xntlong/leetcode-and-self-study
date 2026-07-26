/**
628. Maximum Product of Three Numbers
    Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

        Example 1: 
    Input: nums = [1,2,3]
    Output: 6
 */



class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;

        long long min1 = LLONG_MAX;
        long long min2 = LLONG_MAX;

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};