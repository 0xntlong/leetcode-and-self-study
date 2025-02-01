/*
3151. Special Array I
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

    Example 1:
    Input: nums = [1]
    Output: true
    Explanation:
    There is only one element. So the answer is true.
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        bool prev = nums[0] & 1;
        for (int i = 1; i < n; i++){
            bool x = nums[i] & 1;
            if (x ^ prev == 0)
                return 0;
            prev = x;
        }
        return 1;
    }
};