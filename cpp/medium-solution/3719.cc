/**
3719. Longest Balanced Subarray I
    You are given an integer array nums.
    A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example :
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (res > n - i) 
                break;
            unordered_set<int> visited;
            int balance = 0;
            for (int j = i; j < n; j++) {
                int num = nums[j];
                if (!visited.count(num)) {
                    balance += (num % 2 == 0) ? 1 : -1;
                    visited.insert(num);
                }
                if (balance == 0) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};