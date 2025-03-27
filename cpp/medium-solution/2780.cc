/*
2780. Minimum Index of a Valid Split
    An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
    You are given a 0-indexed integer array nums of length n with one dominant element.
    You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
    0 <= i < n - 1
    nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
    Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
    Return the minimum index of a valid split. If no valid split exists, return -1.

    Example :
    Input: nums = [1,2,2,2]
    Output: 2
    Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
    In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
    In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
    Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
    It can be shown that index 2 is the minimum index of a valid split. 
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
            int idx = -1;
            for (int i : nums){
                if (count == 0){
                    idx = i;
                }
                count += (i == idx) ? 1 : -1;
            }
            unordered_map<int, int> freq;
            for (int i : nums){
                freq[i]++;
            }
            int countFreq = 0;
            for (int j = 0; j < n; j++){
                countFreq += (nums[j] == idx);
                if (countFreq * 2 > (j + 1) && (freq[idx] - countFreq) * 2 > (n - j - 1)){
                    return j;
                } 
            }
            return -1;
        }
    };