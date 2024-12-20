/*
2148. Count Elements With Strictly Smaller and Greater Elements
    Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.

    Example :
    Input: nums = [11,7,2,15]
    Output: 2
    Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
    Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
    In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums) {
        int minE = *min_element(nums.begin(), nums.end());
        int maxE = *max_element(nums.begin(), nums.end());
        int count = 0;
        for (int num : nums){
            if (num > minE && num < maxE){
                count++;
            }
        }
        return count;
    }
}; 