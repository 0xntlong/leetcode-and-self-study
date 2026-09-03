/**
3876. Construct Uniform Parity Array II
    You are given an array nums1 of n distinct integers.
    You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
    For each index i, you must choose exactly one of the following (in any order):
    nums2[i] = nums1[i]​​​​​​​
    nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
    Return true if it is possible to construct such an array, otherwise return false.

    Example :
    Input: nums1 = [1,4,7]
    Output: true
    Explanation:​​​​​​​​​​​​​​
    Set nums2[0] = nums1[0] = 1.
    Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
    Set nums2[2] = nums1[2] = 7.
    nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
 */



class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minNum = *min_element(nums1.begin(), nums1.end());

        if (minNum & 1) {
            return true;
        }

        for (int n : nums1) {
            if (n & 1) {
                return false;
            }
        }

        return true;
    }
};