/*
2164. Sort Even Indices Independently
    You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
    Sort the values at odd indices of nums in non-increasing order.
    For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
    Sort the values at even indices of nums in non-decreasing order.
    For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
    Return the array formed after rearranging the values of nums.

    Example :
    Input: nums = [4,1,2,3]
    Output: [2,3,4,1]
    Explanation: 
    First, we sort the values present at odd indices (1 and 3) in non-increasing order.
    So, nums changes from [4,1,2,3] to [4,3,2,1].
    Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
    So, nums changes from [4,1,2,3] to [2,3,4,1].
    Thus, the array formed after rearranging the values is [2,3,4,1].
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for(int i = 0; i < n; i++){
            if ( i % 2 == 0)
                even.push_back(nums[i]);
            else 
                odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        int i = 0, j = 0;
        for (int k = 0; k < n; k++){
            if ( k % 2 == 0)
                nums[k] = even[i++];
            else 
                nums[k] = odd[j++];
        }
        return nums;
    }
};