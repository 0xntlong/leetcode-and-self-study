/*
1413. Minimum Value to Get Positive Step by Step Sum
    Given an array of integers nums, you start with an initial positive value startValue.
    In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
    Return the minimum positive value of startValue such that the step by step sum is never less than 1.

    Example :
    Input: nums = [-3,2,-3,4,2]
    Output: 5
    Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
    step by step sum
    startValue = 4 | startValue = 5 | nums
    (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
    (1 +2 ) = 3  | (2 +2 ) = 4    |   2
    (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
    (0 +4 ) = 4  | (1 +4 ) = 5    |   4
    (4 +2 ) = 6  | (5 +2 ) = 7    |   2
*/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        for ( int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum < 1){
                res += (1 - sum);
                sum = 1;
            }
        }
        if (res == 0)
            res = 1;
        return res;
    }
};