/*
2040. Kth Smallest Product of Two Sorted Arrays
    Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

    Example :
    Input: nums1 = [2,5], nums2 = [3,4], k = 2
    Output: 8
    Explanation: The 2 smallest products are:
    - nums1[0] * nums2[0] = 2 * 3 = 6
    - nums1[0] * nums2[1] = 2 * 4 = 8
    The 2nd smallest product is 8.
 */

#include <vector>
using namespace std;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0) count += nums2.size();
                continue;
            }
            int low = 0, high = nums2.size();
            if (num1 > 0) {
                while (low < high) {
                    int mid = low + (high - low) / 2;
                    if (1LL * num1 * nums2[mid] <= target)
                        low = mid + 1;
                    else
                        high = mid;
                }
                count += low;
            } else {
                while (low < high) {
                    int mid = low + (high - low) / 2;
                    if (1LL * num1 * nums2[mid] <= target)
                        high = mid;
                    else
                        low = mid + 1;
                }
                count += nums2.size() - low;
            }
        }
        return count;
    }
};