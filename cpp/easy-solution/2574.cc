/*
2574. Left and Right Sum Differences    
    Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:
    answer.length == nums.length.
    answer[i] = |leftSum[i] - rightSum[i]|.
    Where:
    leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
    rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
    Return the array answer.
    
    Example :
    Input: nums = [10,4,8,3]
    Output: [15,1,11,22]
    Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
    The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
*/

#include <vector>
#include <numeric>
using namespace std;
class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            int prefix = 0;
            int suffix = accumulate(nums.begin(), nums.end(), 0);
            vector<int> res;
            for (int i : nums){
                prefix += i;
                res.push_back(abs(prefix - suffix));
                suffix -= i;
            }
            return res;
        }
    };