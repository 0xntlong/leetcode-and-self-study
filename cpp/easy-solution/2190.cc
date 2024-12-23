/*
2190. Most Frequent Number Following Key In an Array
    You are given a 0-indexed integer array nums. You are also given an integer key, which is present in nums.
    For every unique integer target in nums, count the number of times target immediately follows an occurrence of key in nums. In other words, count the number of indices i such that:
    0 <= i <= nums.length - 2,
    nums[i] == key and,
    nums[i + 1] == target.
    Return the target with the maximum count. The test cases will be generated such that the target with maximum count is unique.

    Example :
    Input: nums = [1,100,200,1,100], key = 1
    Output: 100
    Explanation: For target = 100, there are 2 occurrences at indices 1 and 4 which follow an occurrence of key.
    No other integers follow an occurrence of key, so we return 100.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> counter;
        int count = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == key){
                counter[nums[i + 1]]++;
                if (counter[nums[i + 1]] > count){
                    count = counter[nums[i + 1]];
                    ans = nums[i + 1];
                }
            }
        }
        return ans;
    }
};