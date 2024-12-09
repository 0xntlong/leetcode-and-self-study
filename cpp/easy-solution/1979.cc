/*
1979. Greatest Common Divisor of Array
    Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
    The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

    Example :
    Input: nums = [2,5,6,9,10]
    Output: 2
    Explanation:
    The smallest number in nums is 2.
    The largest number in nums is 10.
    The greatest common divisor of 2 and 10 is 2.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        while (mx != 0){
            int temp = mx;
            mx = mn % mx;
            mn = temp;
        }
        return mn;
    }
};