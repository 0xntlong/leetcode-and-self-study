/**
976. Largest Perimeter Triangle
    Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
    Example :
    Input: nums = [2,1,2]
    Output: 5
    Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
 */



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--){
            if (i - 2 >= 0 && i - 1 >= 0){
                if (nums[i - 2] + nums[i - 1] > nums[i]){
                    return nums[i - 2] + nums[i - 1] + nums[i];
                }
            }
        }
        return 0;
    }
};