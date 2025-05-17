/*
75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Example :
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 1, blue = 2;
        int left = 0, mid = 0, right = (int)nums.size() - 1;
        while (mid <= right){
            int i = nums[mid];
            if (i == red){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
            else if (i == white){
                mid++;
            }
            else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};