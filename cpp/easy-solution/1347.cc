/*
1347. Minimum Number of Steps to Make Two Strings Anagram
    Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
    
    Example :
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
*/

#include <vector>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int j = -1;
        for (int i = 0; i < n; i++){
            if(nums[i]){
                if(i -j -1 >= k || j == -1)
                    j = i;
                else
                    return false;
            }
        }
        return true;
    }
};