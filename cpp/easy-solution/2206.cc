/*
2206. Divide Array Into Equal Pairs
    You are given an integer array nums consisting of 2 * n integers.
    You need to divide nums into n pairs such that:
    Each element belongs to exactly one pair.
    The elements present in a pair are equal.
    Return true if nums can be divided into n pairs, otherwise return false.

    Example: 
    Input: nums = [3,2,3,2,2,2]
    Output: true
    Explanation: 
    There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
    If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums){
            freq[i]++;
        }
        for (auto& [key, count] : freq){
            if (count % 2 != 0){
                return false;
            }
        }
        return true;
    }
};