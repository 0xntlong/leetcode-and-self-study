/*
1636. Sort Array by Increasing Frequency
    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
    Return the sorted array.

    Example :
    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::unordered_map<int, int> count;
        for (int num : nums){
            count[num]++;
        }
        std::sort(nums.begin(), nums.end(), [&](int a, int b){
            if (count[a] == count[b]){
                return a > b;
            }
            return count[a] < count[b];
        });
        return nums;
    }
};