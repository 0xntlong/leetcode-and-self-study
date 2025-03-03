/*
2605. Form Smallest Number From Two Digit Arrays
    Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

    Example :
    Input: nums1 = [4,1,3], nums2 = [5,7]
    Output: 15
    Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
*/

#include <vector>
#include <unordered_set>
class Solution {
    public:
        int minNumber(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
            int commonMin = INT_MAX, min1 = INT_MAX, min2 = INT_MAX;
            for (int num : nums1){
                if (set2.count(num))
                    commonMin = min(commonMin, num);
                min1 = min(min1, num);
            }
            for (int num : nums2){
                min2 = min(min2, num);
            }
            if (commonMin != INT_MAX)
                return commonMin;
            return min(min1 * 10 + min2, min2 * 10 + min1);
        }
    };