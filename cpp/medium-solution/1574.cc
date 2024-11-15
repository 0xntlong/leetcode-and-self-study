/*
1574. Shortest Subarray to be Removed to Make Array Sorted
    Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
    Return the length of the shortest subarray to remove.
    A subarray is a contiguous subsequence of the array.

    Example :
    Input: arr = [1,2,3,10,4,2,3,5]
    Output: 3
    Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
    Another correct solution is to remove the subarray [3,10,4].
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        for (; left + 1 < n && arr[left] <= arr[left + 1]; left++);
        if (left == n - 1)
            return 0;
        vector<int> stack = {n - 1};
        for (int right = n - 2; right > left; right--){
            if (arr[right] <= arr[right + 1])
                stack.push_back(right);
            else break; 
        }
        int remove = min(n - left - 1, stack.back());
        for (int i = 0; i <= left; i++){
            while (!stack.empty() && arr[i] > arr[stack.back()])
                stack.pop_back();
            if (!stack.empty())
                remove = min(remove, stack.back() - i - 1);
        }
        return remove;
    }
};