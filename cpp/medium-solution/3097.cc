/*
3097. Shortest Path in a Hidden Grid
You are given an array nums of non-negative integers and an integer k.
An array is called special if the bitwise OR of all of its elements is at least k.
Return the length of the shortest special non-empty 
subarray of nums, or return -1 if no special subarray exists.

Example :
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> BitCount (32, 0);
        int XOR = 0;
        int left = 0;
        int Min = INT_MAX;
        for( int right = 0; right < n; right++){
            XOR |= nums[right];
            for (int bit = 0; bit < 32; bit++){
                if (nums[right] & (1 << bit)){
                    BitCount[bit]++;
                }
            }
            while (left <= right && XOR >= k){
                Min = min(Min, right - left + 1);
                int UpdateXOR = 0;
                for ( int bit = 0; bit < 32; bit++){
                    if (nums[left] & (1 << bit)){
                        BitCount[bit]--;
                    }
                    if (BitCount[bit] > 0){
                        UpdateXOR |= (1 << bit);
                    }   
                }
                XOR = UpdateXOR;
                left++;
            }
        }
        return Min == INT_MAX ? -1 : Min; 
    }
};