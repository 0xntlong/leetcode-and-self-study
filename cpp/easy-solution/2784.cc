/**
2784. Check if Array is Good
    You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].
    base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].
    Return true if the given array is good, otherwise return false.
    Note: A permutation of integers represents an arrangement of these numbers.

    Example :
    Input: nums = [2, 1, 3]
    Output: false
    Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
 */

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_num = nums;
        sort(sorted_num.begin(), sorted_num.end());
        vector<int> expected;
        for (int i = 1; i < n; i++) {
            expected.push_back(i);
        }

        expected.push_back(n - 1);
        return expected == sorted_num;
    }
};