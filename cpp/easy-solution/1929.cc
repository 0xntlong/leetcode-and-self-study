/*
1929. Concatenation of Array
    Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
    Specifically, ans is the concatenation of two nums arrays.
    Return the array ans.

    Example :
    Input: nums = [1,2,1]
    Output: [1,2,1,1,2,1]
    Explanation: The array ans is formed as follows:
    - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
    - ans = [1,2,1,1,2,1]
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums){
        int n = nums.size();
        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};