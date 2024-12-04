/*
1909. Remove One Element to Make the Array Strictly Increasing
    Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.
    The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

    Example :
    Input: nums = [1,2,10,5,7]
    Output: true
    Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
    [1,2,5,7] is strictly increasing, so return true.
*/

#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        stack<int> st;
        int count = 0;
        for (auto e : nums){
            while(!st.empty() && st.top() >= e){
                count++;
                st.pop();
            } 
            st.push(e);
        }
    while (!st.empty())
        st.pop();
    int count2 = 0;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            count2++;
            st.pop();
        }
        st.push(nums[i]);
    }
    if (count == 0 || count == 1 || count2 == 0 || count2 == 1)
        return true;
    return false;
    }
};