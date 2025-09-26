/**
611. Valid Triangle Number
    Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
    Example 1:
    Input: nums = [2,2,3,4]
    Output: 3
    Explanation: Valid combinations are: 
    2,3,4 (using the first 2)
    2,3,4 (using the second 2)
    2,2,3
 */


#include <vector>
#include <algorithm>
#using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        if (n <= 2) 
            return 0;
        for (int k = 2; k < n; k++){
            int i = 0;
            int j = k - 1;
            while (i < j){
                if (nums[i] + nums[j] > nums[k]){
                    count += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};