/*
2441. Largest Positive Interger That Exitsts Withs Its Nagative 
    Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
    Return the positive integer k. If there is no such integer, return -1.

    Example :
    Input: nums = [-1,2,-3,3]
    Output: 3
    Explanation: 3 is the only valid k we can find in the array.
*/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i : nums){
            if (i < 0){
                hash.insert(i);
            }
        }
        int max_k = -1;
        for (int i : nums){
            if (i > 0 && hash.find(-i) != hash.end()){
                max_k = max(max_k, i);
            }
        }
        return max_k;
    }
};