/*
2239. Closest Number to 0
    Given an integer array nums of size n, return the number with the value closest to 0 in nums. If there are multiple answers, return the number with the largest value.

    Example :
    Input: nums = [-4,-2,1,4,8]
    Output: 1
    Explanation:
    The distance from -4 to 0 is |-4| = 4.
    The distance from -2 to 0 is |-2| = 2.
    The distance from 1 to 0 is |1| = 1.
    The distance from 4 to 0 is |4| = 4.
    The distance from 8 to 0 is |8| = 8.
    Thus, the closest number to 0 in the array is 1.
*/

#include <vector>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = nums[0];
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            if (abs(nums[i]) < abs(dist) || (abs(nums[i] == abs(dist) && nums[i] > dist))){
                dist = nums[i];
            }
        }
        return dist;
    }
};