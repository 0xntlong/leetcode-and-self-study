/*
1822. Sign of the Product of an Array
    Implement a function signFunc(x) that returns:
    1 if x is positive.
    -1 if x is negative.
    0 if x is equal to 0.
    You are given an integer array nums. Let product be the product of all values in the array nums.
    Return signFunc(product).

    Example :
    Input: nums = [-1,-2,-3,-4,3,2,1]
    Output: 1
    Explanation: The product of all values in the array is 144, and signFunc(144) = 1
*/

#include <vector>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 1;
        for (int n : nums){
            if (n == 0){
                return 0;
            } else if (n < 0) {
                count *= -1;
            }
        }
        return count;
    }
};