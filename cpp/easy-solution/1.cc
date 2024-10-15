/*
1. Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    
    Example:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <vector>
#include <unordered_map>
using namespace std;
class solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> num_dict;
            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                if (num_dict.find(complement) != num_dict.end()) {
                    return {num_dict[complement], i};
                }
                num_dict[nums[i]] = i;
            }
            return {};
    }
};