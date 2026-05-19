/*
2540. Minimum Common Value
    Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
    Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

    Example :
    Input: nums1 = [1,2,3], nums2 = [2,4]
    Output: 2
    Explanation: The smallest element common to both arrays is 2, so we return 2.
*/

#include <vector>
using namespace std;
class Solution {
    public:
        int getCommon(vector<int>& nums1, vector<int>& nums2) {
            int s1 = 0;
            int s2 = 0;
            int n1 = nums1.size();
            int n2 = nums2.size();
            if (nums1[n1 - 1] < nums2[0])
                return -1;
            if (nums2[n2 - 1] < nums1[0])
                return -1;
            while (s1 < n1 && s2 < n2) {
                if (nums1[s1] == nums2[s2])
                    return nums1[s1];
                else if (nums1[s1] < nums2[s2])
                    s1++;
                else
                    s2++;
            }
            return -1;
        }
    };