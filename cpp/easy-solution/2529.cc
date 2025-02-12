/*
2529. Maximum Count of Positive Integer and Negative Integer
    Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
    In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
    Note that 0 is neither positive nor negative.

    Example :
    Input: nums = [-2,-1,-1,1,2,3]
    Output: 3
    Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
*/

#include <vector>
using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int pos = 0;
            int neg = 0;
            for (int i : nums){
                if (i > 0) pos++;
                else if (i < 0) neg++;
                else continue;
            }
            return max(pos, neg);
        }
    };

