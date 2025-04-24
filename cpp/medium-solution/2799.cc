/*
2799. Count Complete Subarrays in an Array
    You are given an array nums consisting of positive integers.
    We call a subarray of an array complete if the following condition is satisfied:
    The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
    Return the number of complete subarrays.
    A subarray is a contiguous non-empty part of an array.
    Example :
    Input: nums = [1,3,1,2,2]
    Output: 4
    Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int res = 0;
            int left = 0;
            unordered_set<int> unique(nums.begin(), nums.end());
            int k = unique.size();
            unordered_map<int, int>mp;
            for (int i = 0; i < nums.size(); i++){
                mp[nums[i]]++;
                while (mp.size() == k){
                    res += nums.size() - i;
                    mp[nums[left]]--;
                    if (mp[nums[left]] == 0){
                        mp.erase(nums[left]);
                    }
                    left++;
                }
            }
            return res;
        }
    };