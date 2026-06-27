/**
3020. Find the Maximum Number of Elements in Subset
    You are given an array of positive integers nums.
    You need to select a subset of nums which satisfies the following condition:
    You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
    Return the maximum number of elements in a subset that satisfies these conditions.
    Example:
    Input: nums = [5,4,1,2,2]
    Output: 3
    Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 22 == 4. Hence the answer is 3.
 */



class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int x : nums) {
            count[x]++;
        }
        int res = 0;
        for (auto& [num, freq] : count) {
            long long key = num;
            int total = 0;
            if (key == 1) {
                total = (freq % 2 == 1) ? freq : freq - 1;
            } else {
                while (count[key] >= 2 && count.count(key * key)) {
                    total += 2;
                    key = key * key;
                }
                total += 1;
            }
            res = max(res, total);
        }
        return res;
    }
};