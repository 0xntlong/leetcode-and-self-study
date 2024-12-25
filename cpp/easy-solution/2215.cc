/*
2215. Find the Difference of Two Arrays
    Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
    Note that the integers in the lists may be returned in any order.

    Example :
    Input: nums1 = [1,2,3], nums2 = [2,4,6]
    Output: [[1,3],[4,6]]
    Explanation:
    For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
    For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> dis1 , dis2;
        while (i < n1 && j < n2){
            if (i > 0){
                while (i < n1 && nums1[i] == nums1[i - 1])
                    i++;
                if (i == n1)
                    break;
            }
            if (j > 0){
                while (j < n2 && nums2[j] == nums2[j - 1])
                    j++;
                if (j == n2)
                    break;
            }
            if (nums1[i] == nums2[j]){
                i++;
                j++;
            } else if (nums1[i] < nums2[j]){
                dis1.push_back(nums1[i++]);
            } else {
                dis2.push_back(nums2[j++]);
            }
        }
        while (i < n1){
            if (i > 0){
                while ( i < n1 && nums1[i] == nums1[i - 1])
                    i++;
                if (i == n1)
                    break;
            }
            dis1.push_back(nums1[i++]);
        }
        while (j < n2){
            if (j > 0){
                while (j < n2 && nums2[j] == nums2[j - 1])
                    j++;
                if (j == n2)
                    break;
            }
            dis2.push_back(nums2[j++]);
        }
        return {dis1, dis2};
    }
};