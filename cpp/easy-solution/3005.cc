/**
3005. Count Elements With Maximum Frequency
    You are given an array nums consisting of positive integers.

    Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

    The frequency of an element is the number of occurrences of that element in the array.

    

    Example:

    Input: nums = [1,2,2,3,1,4]
    Output: 4
    Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
    So the number of elements in the array with maximum frequency is 4.
 */


#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums){
            freq[n]++;
        }
        int max_freq = 0;
        for (auto& [key, value] : freq){
            max_freq = max(max_freq, value);
        }
        int total = 0;
        for (auto& [key, value] : freq){
            if (value == max_freq)
                total += value;
        }
        return total;
    }
};