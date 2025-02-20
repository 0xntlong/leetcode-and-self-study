/*
2553. Separate the Digits in an Array
    Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.
    To separate the digits of an integer is to get all the digits it has in the same order.
    For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
    Example :
    Input: nums = [13,25,83,77]
    Output: [1,3,2,5,8,3,7,7]
    Explanation: 
    - The separation of 13 is [1,3].
    - The separation of 25 is [2,5].
    - The separation of 83 is [8,3].
    - The separation of 77 is [7,7].
    answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<int> separateDigits(vector<int>& nums) {
            vector<int> res;
            for (int i = 0; i < nums.size(); i++){
                string num = to_string(nums[i]);
                for (int j = 0; j < num.size(); j++){
                    res.push_back(num[j] - '0');
                }
            }
            return res;
        }
    };