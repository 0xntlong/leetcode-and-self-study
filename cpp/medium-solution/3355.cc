/* 
3355. Zero Array Transformation I
    You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
    For each queries[i]:
    Select a subset of indices within the range [li, ri] in nums.
    Decrement the values at the selected indices by 1.
    A Zero Array is an array where all elements are equal to 0.
    Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

    Example :
    Input: nums = [1,0,1], queries = [[0,2]]
    Output: true
    Explanation:
    For i = 0:
    Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
    The array will become [0, 0, 0], which is a Zero Array.
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for (const auto& q : queries){
            int l = q[0], r = q[1];
            freq[l]++;
            if (r + 1 < n){
                freq[r + 1]--;
            }

        }
        int rsum = 0;
        for (int i = 0; i < n; i++){
            rsum += freq[i];
            if (nums[i] > rsum){
                return false;
            }
        }
        return true;
    }
};