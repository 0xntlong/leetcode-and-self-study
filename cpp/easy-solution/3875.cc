/**
3875. Construct Uniform Parity Array I
    You are given an array nums1 of n distinct integers.
    You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
    For each index i, you must choose exactly one of the following (in any order):
    nums2[i] = nums1[i]
    nums2[i] = nums1[i] - nums1[j], for an index j != i
    Return true if it is possible to construct such an array, otherwise, return false.

    Example :
    Input: nums1 = [2,3]
    Output: true
    Explanation:
    Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1.
    Choose nums2[1] = nums1[1] = 3.
    nums2 = [-1, 3], and both elements are odd. Thus, the answer is true​​​​​​​.
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // return 1;
        int odd = 0;
        int even = 0;

        int n = nums1.size();

        for (int x : nums1) {
            if (x % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        if (even == n || odd == n) {
            return true;
        } else if (even >= 1 && odd >= 1) {
            return true;
        }

        return false;
    }
};