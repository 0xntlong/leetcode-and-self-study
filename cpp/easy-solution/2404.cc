/*
2404. Most Frequent Even Element
    Given an integer array nums, return the most frequent even element.
    If there is a tie, return the smallest one. If there is no such element, return -1.

    Example :
    Input: nums = [0,1,2,2,4,4,1]
    Output: 2
    Explanation:
    The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
    We return the smallest one, which is 2.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }
        
        int res = -1, maxFreq = 0;
        for (const auto& [key, value] : freq) {
            if (value > maxFreq || (value == maxFreq && key < res)) {
                maxFreq = value;
                res = key;
            }
        }
        
        return res;
    }
};