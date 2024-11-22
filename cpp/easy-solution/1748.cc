/*
1748. Sum of Unique Elements
    You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
    Return the sum of all the unique elements of nums.

    Example :
    Input: nums = [1,2,3,2]
    Output: 4
    Explanation: The unique elements are [1,3], and the sum is 4.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int s = 0;
        unordered_map<int, int> array;
        for (int i = 0; i < nums.size(); i++){
            array[nums[i]]++;
        }
        for (auto& j : array){
            if (j.second == 1){
                s = s + j.first;
            }
        }
        return s;
    }
};